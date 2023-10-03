import pygame as pg
import os
import numpy as np
import pychess as pc
import chess

class Graphic:
	def __init__(self, FEN):
		self.chess_ai = pc.ChessAI(FEN)

		pg.init()
		self.size = 600
		self.scr = pg.display.set_mode((self.size + 300, self.size))
		self.bg = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "board.png"))
		self.bg = pg.transform.scale(self.bg, [self.size]*2)
		self.loadImage()
		self.font = pg.font.SysFont('Arial.ttf', 32)

	def __init__(self):
		self.chess_ai = pc.ChessAI()

		pg.init()
		self.size = 600
		self.scr = pg.display.set_mode((self.size + 300, self.size))
		self.bg = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "board.png"))
		self.bg = pg.transform.scale(self.bg, [self.size]*2)
		self.loadImage()
		self.font = pg.font.SysFont('Arial.ttf', 40)

	def loadImage(self):
		R = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "Wr.png"))
		N = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "Wn.png"))
		B = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "Wb.png"))
		Q = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "Wq.png"))
		K = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "Wk.png"))
		P = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "Wp.png"))
		r = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "BR.png"))
		n = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "BN.png"))
		b = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "BB.png"))
		q = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "BQ.png"))
		k = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "BK.png"))
		p = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "BP.png"))

		self.chesspiece = {
			'R' : pg.transform.scale(R, [self.size//8]*2),
			'N' : pg.transform.scale(N, [self.size//8]*2),
			'B' : pg.transform.scale(B, [self.size//8]*2),
			'Q' : pg.transform.scale(Q, [self.size//8]*2),
			'K' : pg.transform.scale(K, [self.size//8]*2),
			'P' : pg.transform.scale(P, [self.size//8]*2),
			'r' : pg.transform.scale(r, [self.size//8]*2),
			'n' : pg.transform.scale(n, [self.size//8]*2),
			'b' : pg.transform.scale(b, [self.size//8]*2),
			'q' : pg.transform.scale(q, [self.size//8]*2),
			'k' : pg.transform.scale(k, [self.size//8]*2),
			'p' : pg.transform.scale(p, [self.size//8]*2)
		}

		black = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "black_check.png"))
		self.black = pg.transform.scale(black, [self.size // 6]*2)
		white = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "white_check.png"))
		self.white = pg.transform.scale(white, [self.size // 6]*2)

		winner = pg.image.load(os.path.join("E:/University_Code/ChessProject/python/Image2", "winner.png"))
		self.winner = pg.transform.scale(winner, [self.size // 6 * 2]*2)

	def displayChess(self, FEN):
		self.scr.blit(self.bg, (0,0))
		i = 0
		j = 0
		for c in FEN:
			if '0' <= c <= '9':
				j += int(c)
			elif ('a' <= c <= 'z') or ('A' <= c <= 'Z'):
				self.scr.blit(self.chesspiece[c], (j * self.size//8, i * self.size//8))
				j += 1
			else:
				i += 1
				j = 0

	def displayCheck(self, player_turn):
		size = self.size // 6
		if player_turn:
			self.scr.blit(self.black, (self.size + (300 - size) // 2, (self.size // 2 - size) // 2))
		else:
			self.scr.blit(self.white, (self.size + (300 - size) // 2, self.size // 2 + (self.size // 2 - size) // 2))

	def displayCheckMate(self):
		size = self.size // 6
		if self.chess_ai.winner():
			rect = pg.Rect(self.size, 0, 300, self.size)
			pg.draw.rect(self.scr, (255, 255, 255), rect)
			self.scr.blit(self.white, (self.size + (300 - size) // 2, (self.size // 2 - size) // 5 * 4))
		else:
			rect = pg.Rect(self.size, 0, 300, self.size)
			pg.draw.rect(self.scr, (0, 0, 0), rect)
			self.scr.blit(self.black, (self.size + (300 - size) // 2, (self.size // 2 - size) // 5 * 4))

		self.scr.blit(self.winner, (self.size + (300 - size*2) // 2, self.size // 2 + (self.size // 2 - size*2) // 5))

		text = self.font.render('Press SPACE', True, (0, 255, 0))
		textRect = text.get_rect()
		textRect.center = (textRect[0] // 2, textRect[1] // 2)
		self.scr.blit(text, (self.size + (300 - text.get_rect()[2]) // 2, self.size-text.get_rect()[3]-20))

	def displayBackground(self, player_turn):
		if player_turn:
			rect = pg.Rect(self.size, self.size//2, 300, self.size//2)
			pg.draw.rect(self.scr, (255, 255, 255), rect)
			rect = pg.Rect(self.size, 0, 300, self.size//2)
			pg.draw.rect(self.scr, (150, 150, 150), rect)
			rect = pg.Rect(self.size+100, (self.size//2 - 100)//2 + self.size//2, 100, 100)
			pg.draw.rect(self.scr, (200, 100, 0), rect)
		else:
			rect = pg.Rect(self.size, self.size//2, 300, self.size//2)
			pg.draw.rect(self.scr, (205, 205, 205), rect)
			rect = pg.Rect(self.size, 0, 300, self.size//2)
			pg.draw.rect(self.scr, (0, 0, 0), rect)
			rect = pg.Rect(self.size+100, (self.size//2 - 100)//2, 100, 100)
			pg.draw.rect(self.scr, (200, 0, 0), rect)			

	def getValidMove(self):
		return self.chess_ai.getLegalMove()

	def displayValidMove(self, curr_pos):
		if not curr_pos:
			return
		validMoves = []
		for i in self.chess_ai.getLegalMove():
			if i[:2] == curr_pos:
				x = ord(i[2]) - ord('a')
				y = ord(i[3]) - ord('0') - 1
				validMoves.append((x, y))

		square_size = self.size // 8

		rect = pg.Rect((ord(curr_pos[0])-ord('a'))*square_size, (7-(ord(curr_pos[1])-ord('0')-1))*square_size, square_size, square_size)
		pg.draw.rect(self.scr, (255, 0, 0), rect, 3)

		for i in validMoves:
			rect = pg.Rect(i[0]*square_size, (7-i[1])*square_size, square_size, square_size)
			pg.draw.rect(self.scr, (0, 255, 0), rect, 3)

	def RUN(self):
		running = True
		curr_pos = ''
		next_pos = ''
		player_turn = True

		while running:
			self.displayBackground(player_turn)
			if self.chess_ai.isCheckMate():
				self.displayCheckMate()
			elif self.chess_ai.isCheck():
				self.displayCheck(player_turn)
			self.displayChess(self.chess_ai.getFEN())
			self.displayValidMove(curr_pos)

			pg.display.flip()

			for event in pg.event.get():
				if event.type == pg.QUIT:
					running = False
				elif event.type == pg.MOUSEBUTTONDOWN:
					x, y = pg.mouse.get_pos()
					if not curr_pos:
						curr_pos = chr(x//(self.size//8)+ord('a')) + chr(7-y//(self.size//8)+1+ord('0'))
					else:
						next_pos = chr(x//(self.size//8)+ord('a')) + chr(7-y//(self.size//8)+1+ord('0'))
				elif event.type == pg.KEYDOWN:
					if event.key == pg.K_SPACE:
						self.chess_ai = pc.ChessAI()
						curr_pos = ''
						next_pos = ''
						player_turn = True

			if curr_pos == next_pos:
				next_pos = ''

			if not player_turn:
				s, move, _ = self.chess_ai.alphabeta(-2000, 2000, 4, player_turn)
				curr_pos = move[:2]
				next_pos = move[2:]

			if curr_pos and next_pos:
				if f'{curr_pos}{next_pos}' in self.getValidMove():
					self.chess_ai.moveFromTo(curr_pos, next_pos)
					player_turn = not player_turn
					curr_pos = ''
					next_pos = ''
				elif f'{curr_pos}{next_pos}q' in self.getValidMove():
					self.chess_ai.moveFromTo(curr_pos, f'{next_pos}q')
					player_turn = not player_turn
					curr_pos = ''
					next_pos = ''
				else:
					curr_pos = next_pos
					next_pos = ''

if __name__ == '__main__':
	graphic = Graphic()
	graphic.RUN()