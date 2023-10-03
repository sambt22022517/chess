import chess
import numpy as np

PAWN = np.array([
		[0,0,0,0,0,0,0,0],
		[0.5,1,1,-2,-2,1,1,0.5],
		[0.5,-0.5,-1.0,0,0,-1,-0.5,0.5],
		[0,0,0,2,2,0,0,0],
		[0.5,0.5,1,2.5,2.5,1,0.5,0.5],
		[1,1,2,3,3,2,1,1],
		[5,5,5,5,5,5,5,5],
		[0,0,0,0,0,0,0,0]
		])

KNIGHT = np.array([	
			[-5,-4,-3,-3,-3,-3,-4,-5],
			[-4,-2,0,0.5,0.5,0,-2,-4],
			[-3,0.5,1,1.5,1.5,1,0.5,-3],
			[-3,0,1.5,2,2,1.5,0,-3],
			[-3,0.5,1.5,2,2,1.5,0.5,-3],
			[-3,0,1,1.5,1.5,1,0,-3],
			[-4,-2,0,0,0,0,-2,-4],
			[-5,-4,-3,-3,-3,-3,-4,-5]
			])

BISHOP = np.array([
			[-2,-1,-1,-1,-1,-1,-1,-2],
			[-1,0.5,0,0,0,0,0.5,-1],
			[-1,1,1,1,1,1,1,-1],
			[-1,0,1,1,1,1,0,-1],
			[-1,0.5,0.5,1,1,0.5,0.5,-1],
			[-1,0,0.5,1,1,0.5,0,-1],
			[-1,0,0,0,0,0,0,-1],
			[-2,-1,-1,-1,-1,-1,-1,-2]
			])

ROCK = np.array([
			[0,0,0,0.5,0.5,0,0,0],
			[-0.5,0,0,0,0,0,0,-0.5],
			[-0.5,0,0,0,0,0,0,-0.5],
			[-0.5,0,0,0,0,0,0,-0.5],
			[-0.5,0,0,0,0,0,0,-0.5],
			[-0.5,0,0,0,0,0,0,-0.5],
			[0.5,1,1,1,1,1,1,0.5],
			[0,0,0,0,0,0,0,0]
			])

QUEEN = np.array([
			[-2,-1,-1,-0.5,-0.5,-1,-1,-2],
			[-1,0,0.5,0,0,0,0,-1],
			[-1,0.5,0.5,0.5,0.5,0.5,0,-1],
			[0,0,0.5,0.5,0.5,0.5,0,-0.5],
			[-0.5,0,0.5,0.5,0.5,0.5,0,-0.5],
			[-1,0,0.5,0.5,0.5,0.5,0,-1],
			[-1,0,0,0,0,0,0,-1],
			[-2,-1,-1,-0.5,-0.5,-1,-1,-2]
			])

KING = np.array([
			[2,3,1,0,0,2,3,1],
			[2,2,0,0,0,0,2,2],
			[-1,-2,-2,-2,-2,-2,-2,-1],
			[-2,-3,-3,-4,-4,-3,-3,-2],
			[-3,-4,-4,-5,-5,-4,-4,-3],
			[-3,-4,-4,-5,-5,-4,-4,-3],
			[-3,-4,-4,-5,-5,-4,-4,-3],
			[-3,-4,-4,-5,-5,-4,-4,-3]
			])

SCORE_POS = {
	'r' : ROCK[::-1],
	'n' : KNIGHT[::-1],
	'b' : BISHOP[::-1],
	'q' : QUEEN[::-1],
	'k' : KING[::-1],
	'p' : PAWN[::-1],
	'R' : ROCK,
	'N' : KNIGHT,
	'B' : BISHOP,
	'Q' : QUEEN,
	'K' : KING,
	'P' : PAWN
}

SCORES = {
	'r' : -5,
	'n' : -3,
	'b' : -3,
	'q' : -9,
	'k' : -1000,
	'p' : -1,
	'R' : 5,
	'N' : 3,
	'B' : 3,
	'Q' : 9,
	'K' : 1000,
	'P' : 1
}

class ChessAI:
	def __init__(self, FEN):
		self.board = chess.Board(FEN)
		self.board.castling_rights |= chess.BB_H1

	def __init__(self):
		self.board = chess.Board()

	def __str__(self):
		return [i.split() for i in str(self.board).split('\n')]


	def getScore(self):
		myboard = self.getBoard()
		s = 0
		for i in range(len(myboard)):
			for j in range(len(myboard[i])):
				c = myboard[i][j]
				if c.isalpha():
					if c.isupper():
						s += SCORES[c] + SCORES[c] // abs(SCORES[c]) * SCORE_POS[c][i][j]
		return s

	def alphabeta(self, _alpha, _beta, depth, white_turn):
		if self.board.is_checkmate():
			score = (20000 if self.board.outcome().winner else -20000)
			return [score, '', depth]
		# if self.board.is_stalemate() or self.board.is_insufficient_material() or self.board.is_seventyfive_moves() or self.board.is_fivefold_repetition():
		# 	return [0, '', depth]
		if depth == 0:
			minus = 0
			if self.board.is_checkmate():
				minus = (20000 if self.board.outcome().winner else -20000)
			return [minus, '', depth]

		score = 2000
		max_depth = -1
		MOVE = ""
		alpha = _alpha
		beta = _beta
		validMove = self.board.legal_moves
		for i in validMove:
			next_move = chess.Move.from_uci(str(i))
			self.board.push(next_move)
			next_score, _, DEPTH = self.alphabeta(alpha, beta, depth-1, not white_turn)
			if white_turn:
				if score == 2000 or (score <= next_score and max_depth < DEPTH):
					score = next_score
					MOVE = str(i)
					max_depth = DEPTH
					if score > beta:
						self.board.pop()
						break
					alpha = max(alpha, score)
			else:
				if score == 2000 or (score >= next_score and max_depth < DEPTH):
					score = next_score
					MOVE = str(i)
					max_depth = DEPTH
					if score < alpha:
						self.board.pop()
						break
					beta = min(beta, score)
			self.board.pop()

		return [score, MOVE, max_depth]

	def isCheckMate(self):
		return self.board.is_checkmate()

	def winner(self):
		return self.board.outcome().winner

	def getFEN(self):
		return self.board.fen().split()[0]

	def moveFromTo(self, from_pos, to_pos):
		self.board.push(chess.Move.from_uci(f'{from_pos}{to_pos}'))

	def getLegalMove(self):
		return [str(i) for i in self.board.legal_moves]

	def isCheck(self):
		return self.board.is_check()

	# def isLeftCastling(self):
	# 	return self.board.


if __name__ == '__main__':
	mychess = ChessAI('rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQK2R')
	white_turn = True
	print([str(i) for i in mychess.board.legal_moves])