/*
cách tính điểm quân cờ: tốt 1, xe 5, mã 3 ,tượng 3, hậu 9

*/
/*
vua king/genaral
tốt pawn
xe castle/rock
tượng bishop
mã knight
hậu queen
*/
// G white g black
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
typedef vector<vector<char>> state;
typedef vector<vector<char>> state;
void printRenderGame(state s)//complete
{
	for(int i=0;i<8;i++)
	{
		cout<<char('a'+i);
		for(int j=0;j<8;j++)
		{
			cout<<setw(10);
			switch (s[i][j])
			{
				case 'G':cout<<'K';break;
				case 'g':cout<<'k';break;
				case 'K':cout<<'N';break;
				case 'k':cout<<'n';break;
				default:
					cout<<s[i][j];break;
			}
		}
		cout<<endl<<endl<<endl<<endl;
	}
	cout<<" ";
	for(int i=0;i<8;i++)
	{
		cout<<setw(10)
			<<i+1;
	}
	cout<<endl<<endl<<"_____________________________________________________________________________________"<<endl<<endl;
}
state FirstRenderGame()//complete
{
	state s(8,vector<char> (8));
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			s[i][j]='.';
		}
	}
	//while chessman
	for(int i=0;i<8;i++)
	{
		s[1][i]='P';
	}
	s[0][0]='C';s[0][7]='C';
	s[0][1]='K';s[0][6]='K';
	s[0][2]='B';s[0][5]='B';
	s[0][3]='G';s[0][4]='Q';
	//black chessman
	for(int i=0;i<8;i++)
	{
		s[6][i]='p';
	}
	s[7][0]='c';s[7][7]='c';
	s[7][1]='k';s[7][6]='k';
	s[7][2]='b';s[7][5]='b';
	s[7][3]='g';s[7][4]='q';
	return s;
}
state Move(int i,int j,int i1,int j1 ,state s)//complete
{
	s[i1][j1]=s[i][j];
	s[i][j]='.';
	return s;
}
//pawnWhite
vector<pair<int ,int >> OrdPawnWhite(int i,int j,state s)//complete
{
	vector <pair<int ,int >> ord; //ordinate
	//move
	if(i==1)
	{
		if(s[2][j]=='.')
		{
			ord.push_back(make_pair(2,j));
			if(s[3][j]=='.')
			{
				ord.push_back(make_pair(3,j));
			}
		}
	}
	else
	{
		if(i<7)
		{
			if(s[i+1][j]=='.')
			ord.push_back(make_pair(i+1,j));
		}
	}
	//promotion
	if(i+1<8 && j-1>=0)
	{
		if(s[i+1][j-1]>=97 && s[i+1][j-1]<=122)
		ord.push_back(make_pair(i+1,j-1));
	}
	if(i+1<8 && j+1<8)
	{
		if(s[i+1][j+1]>=97 && s[i+1][j+1]<=122)
		ord.push_back(make_pair(i+1,j+1));
	}
	return ord;
}
vector<pair<int ,int >> OrdPawnWhitePro(int i,int j,state s)//complete
{
	//promotion
	vector <pair<int ,int >> ord; //ordinate
	if(i+1<8 && j-1>=0)
	{
		ord.push_back(make_pair(i+1,j-1));
	}
	if(i+1<8 && j+1<8)
	{
		ord.push_back(make_pair(i+1,j+1));
	}
	return ord;
}
vector<char> To_TakeWhite()//check i==7? Complete
{
	//check i==7?
	vector <char> s;
	s.push_back('Q');
	s.push_back('C');
	s.push_back('K');
	s.push_back('B');
	return s;
}
//castleWhite
vector<pair<int,int>> OrdCastleWhite(int i,int j,state s)//complete
{
	vector<pair<int,int>> ord;
	for(int x=j+1;x<8;x++)
	{
		if(s[i][x]=='.')
		{
			ord.push_back(make_pair(i,x));
		}
		else
		{
			if(s[i][x]>=97 && s[i][x]<=122)
			{
				ord.push_back(make_pair(i,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int x=j-1;x>=0;x--)
	{
		if(s[i][x]=='.')
		{
			ord.push_back(make_pair(i,x));
		}
		else
		{
			if(s[i][x]>=97 && s[i][x]<=122)
			{
				ord.push_back(make_pair(i,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int y=i+1;y<8;y++)
	{
		if(s[y][j]=='.')
		{
			ord.push_back(make_pair(y,j));
		}
		else
		{
			if(s[y][j]>=97 && s[y][j]<=122)
			{
				ord.push_back(make_pair(y,j));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int y=i-1;y>=0;y--)
	{
		if(s[y][j]=='.')
		{
			ord.push_back(make_pair(y,j));
		}
		else
		{
			if(s[y][j]>=97 && s[y][j]<=122)
			{
				ord.push_back(make_pair(y,j));
				break;
			}
			else
			{
				break;
			}
		}
	}
	return ord;
}
//BishopWhite
vector<pair<int,int>> OrdBishopWhite(int i,int j, state s)//complete
{
	vector<pair<int,int>> ord;
	for(int y=i+1,x=j+1;y<8 && x<8;y++,x++)
	{
		if(s[y][x]=='.')
		{
			ord.push_back(make_pair(y,x));
		}
		else
		{
			if(s[y][x]>=97 && s[y][x]<=122)
			{
				ord.push_back(make_pair(y,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int y=i-1,x=j-1;y>=0 && x>=0;y--,x--)
	{
		if(s[y][x]=='.')
		{
			ord.push_back(make_pair(y,x));
		}
		else
		{
			if(s[y][x]>=97 && s[y][x]<=122)
			{
				ord.push_back(make_pair(y,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int y=i-1,x=j+1;y>=0 && x<8;y--,x++)
	{
		if(s[y][x]=='.')
		{
			ord.push_back(make_pair(y,x));
		}
		else
		{
			if(s[y][x]>=97 && s[y][x]<=122)
			{
				ord.push_back(make_pair(y,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int y=i+1,x=j-1;y<8 && x>=0 ;y++,x--)
	{
		if(s[y][x]=='.')
		{
			ord.push_back(make_pair(y,x));
		}
		else
		{
			if(s[y][x]>=97 && s[y][x]<=122)
			{
				ord.push_back(make_pair(y,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	return ord;
}
//knightwhite
vector<pair<int,int>> OrdKnightWhite(int i,int j, state s)//complete
{
	vector<pair<int,int>> ord;
	if(i+1<8 && j+2<8)
	{
		if((s[i+1][j+2]=='.' || (s[i+1][j+2]>=97 && s[i+1][j+2]<=122 ))) ord.push_back(make_pair(i+1,j+2));
	}
	if(i+1<8 && j-2>=0)
	{
		if((s[i+1][j-2]=='.' || (s[i+1][j-2]>=97 && s[i+1][j-2]<=122 ))) ord.push_back(make_pair(i+1,j-2));
	}
	if(i-1>=0 && j+2<8)
	{
		if((s[i-1][j+2]=='.' || (s[i-1][j+2]>=97 && s[i-1][j+2]<=122 ))) ord.push_back(make_pair(i-1,j+2));
	}
	if(i-1>=0 && j-2>=0)
	{
		if((s[i-1][j-2]=='.' || (s[i-1][j-2]>=97 && s[i-1][j-2]<=122 ))) ord.push_back(make_pair(i-1,j-2));
	}
	if(i+2<8 && j+1<8)
	{
		if((s[i+2][j+1]=='.' || (s[i+2][j+1]>=97 && s[i+2][j+1]<=122 ))) ord.push_back(make_pair(i+2,j+1));
	}
	if(i+2<8 && j-1>=0)
	{
		if((s[i+2][j-1]=='.' || (s[i+2][j-1]>=97 && s[i+2][j-1]<=122 ))) ord.push_back(make_pair(i+2,j-1));
	}
	if(i-2>=0 && j+1<8)
	{
		if((s[i-2][j+1]=='.' || (s[i-2][j+1]>=97 && s[i-2][j+1]<=122 ))) ord.push_back(make_pair(i-2,j+1));
	}
	if((i-2>=0 && j-1>=0))
	{
		if((s[i-2][j-1]=='.' || (s[i-2][j-1]>=97 && s[i-2][j-1]<=122 ))) ord.push_back(make_pair(i-2,j-1));
	}
	return ord;
}
//QueenWhite
vector<pair<int,int>> OrdQueenWhite(int i,int j,state s)//complete
{
	vector<pair<int,int>> ord;
	vector<pair<int,int>> copy;
	ord=OrdCastleWhite(i,j,s);
	copy=OrdBishopWhite(i,j,s);
	for(int i=0;i<copy.size();i++)
	{
		ord.push_back(copy[i]);
	}
	return ord;
}
//GeneralWhite
vector<pair<int,int>> OrdGeneralWhite(int i,int j, state s)//complete
{
	vector<pair<int,int>> ord;
	if(i+1<8 && j+1<8)
	{
		if((s[i+1][j+1]=='.' || (s[i+1][j+1]>=97 && s[i+1][j+1]<=122 ))) ord.push_back(make_pair(i+1,j+1));
	}
	if(i+1<8 && j-1>=0)
	{
		if((s[i+1][j-1]=='.' || (s[i+1][j-1]>=97 && s[i+1][j-1]<=122 ))) ord.push_back(make_pair(i+1,j-1));
	}
	if(i-1>=0 && j+1<8)
	{
		if((s[i-1][j+1]=='.' || (s[i-1][j+1]>=97 && s[i-1][j+1]<=122 ))) ord.push_back(make_pair(i-1,j+1));
	}
	if(i-1>=0 && j-1>=0)
	{
		if((s[i-1][j-1]=='.' || (s[i-1][j-1]>=97 && s[i-1][j-1]<=122 ))) ord.push_back(make_pair(i-1,j-1));
	}

	if(i<8 && j+1<8)
	{
		if( (s[i][j+1]=='.' || (s[i][j+1]>=97 && s[i][j+1]<=122 ))) ord.push_back(make_pair(i,j+1));
	}
	if((i<8 && j-1>=0))
	{
		if((s[i][j-1]=='.' || (s[i][j-1]>=97 && s[i][j-1]<=122 ))) ord.push_back(make_pair(i,j-1));
	}
	if(i-1>=0 && j<8)
	{
		if( (s[i-1][j]=='.' || (s[i-1][j]>=97 && s[i-1][j]<=122 ))) ord.push_back(make_pair(i-1,j));
	}
	if((i+1>=0 && j>=0))
	{
		if( (s[i+1][j]=='.' || (s[i+1][j]>=97 && s[i+1][j]<=122 ))) ord.push_back(make_pair(i+1,j));
	}
	return ord;
}
//pawmBlack
vector<pair<int ,int >> OrdPawnBlack(int i,int j,state s)//complete
{
	vector <pair<int ,int >> ord; //ordinate
	if(i==6)
	{
		if(s[5][j]=='.')
		{
			ord.push_back(make_pair(5,j));
			if(s[4][j]=='.')
			{
				ord.push_back(make_pair(4,j));
			}
		}
	}
	else
	{
		if(i>0)
		{
			if(s[i-1][j]=='.')
			ord.push_back(make_pair(i-1,j));
		}
	}
	//promotion
	if(i-1>=0 && j-1>=0)
	{
		if(s[i-1][j-1]>=65 && s[i-1][j-1]<=90)
		ord.push_back(make_pair(i-1,j-1));
	}
	if(i-1>=0 && j+1<8)
	{
		if(s[i-1][j+1]>=65 && s[i-1][j+1]<=90)
		ord.push_back(make_pair(i-1,j+1));
	}
	return ord;
}
vector<pair<int ,int >> OrdPawnBlackPro(int i,int j,state s)//complete
{
	//promotion
	vector <pair<int ,int >> ord; //ordinate
	if(i-1>=0 && j-1>=0)
	{
		ord.push_back(make_pair(i-1,j-1));
	}
	if(i-1>=0 && j+1<8)
	{
		ord.push_back(make_pair(i-1,j+1));
	}
	return ord;
}
vector<char> To_TakeBlack()//check i==0? complete
{
	//check i==0?
	vector <char> s;
	s.push_back('q');
	s.push_back('c');
	s.push_back('k');
	s.push_back('b');
	return s;
}
//castleBlack
vector<pair<int,int>> OrdCastleBlack(int i,int j,state s)//complete
{
	vector<pair<int,int>> ord;
	for(int x=j+1;x<8;x++)
	{
		if(s[i][x]=='.')
		{
			ord.push_back(make_pair(i,x));
		}
		else
		{
			if(s[i][x]>=65 && s[i][x]<=90)
			{
				ord.push_back(make_pair(i,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int x=j-1;x>=0;x--)
	{
		if(s[i][x]=='.')
		{
			ord.push_back(make_pair(i,x));
		}
		else
		{
			if(s[i][x]>=65 && s[i][x]<=90)
			{
				ord.push_back(make_pair(i,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int y=i+1;y<8;y++)
	{
		if(s[y][j]=='.')
		{
			ord.push_back(make_pair(y,j));
		}
		else
		{
			if(s[y][j]>=65 && s[y][j]<=90)
			{
				ord.push_back(make_pair(y,j));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int y=i-1;y>=0;y--)
	{
		if(s[y][j]=='.')
		{
			ord.push_back(make_pair(y,j));
		}
		else
		{
			if(s[y][j]>=65 && s[y][j]<=90)
			{
				ord.push_back(make_pair(y,j));
				break;
			}
			else
			{
				break;
			}
		}
	}
	return ord;
}
//BishopBlack
vector<pair<int,int>> OrdBishopBlack(int i,int j, state s)//complete
{
	vector<pair<int,int>> ord;
	for(int y=i+1,x=j+1;y<8 && x<8;y++,x++)
	{
		if(s[y][x]=='.')
		{
			ord.push_back(make_pair(y,x));
		}
		else
		{
			if(s[y][x]>=65 && s[y][x]<=90)
			{
				ord.push_back(make_pair(y,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int y=i-1,x=j-1;y>=0 && x>=0;y--,x--)
	{
		if(s[y][x]=='.')
		{
			ord.push_back(make_pair(y,x));
		}
		else
		{
			if(s[y][x]>=65 && s[y][x]<=90)
			{
				ord.push_back(make_pair(y,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int y=i-1,x=j+1;y>=0 && x<8;y--,x++)
	{
		if(s[y][x]=='.')
		{
			ord.push_back(make_pair(y,x));
		}
		else
		{
			if(s[y][x]>=65 && s[y][x]<=90)
			{
				ord.push_back(make_pair(y,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	for(int y=i+1,x=j-1;y<8 && x>=0 ;y++,x--)
	{
		if(s[y][x]=='.')
		{
			ord.push_back(make_pair(y,x));
		}
		else
		{
			if(s[y][x]>=65 && s[y][x]<=90)
			{
				ord.push_back(make_pair(y,x));
				break;
			}
			else
			{
				break;
			}
		}
	}
	return ord;
}
//KnightBlack
vector<pair<int,int>> OrdKnightBlack(int i,int j, state s)//complete
{
	vector<pair<int,int>> ord;
	if(i+1<8 && j+2<8)
	{
		if((s[i+1][j+2]=='.' || (s[i+1][j+2]>=65 && s[i+1][j+2]<=90 ))) ord.push_back(make_pair(i+1,j+2));
	}
	if(i+1<8 && j-2>=0)
	{
		if((s[i+1][j-2]=='.' || (s[i+1][j-2]>=65 && s[i+1][j-2]<=90 ))) ord.push_back(make_pair(i+1,j-2));
	}
	if(i-1>=0 && j+2<8)
	{
		if((s[i-1][j+2]=='.' || (s[i-1][j+2]>=65 && s[i-1][j+2]<=90 ))) ord.push_back(make_pair(i-1,j+2));
	}
	if(i-1>=0 && j-2>=0)
	{
		if((s[i-1][j-2]=='.' || (s[i-1][j-2]>=65 && s[i-1][j-2]<=90 ))) ord.push_back(make_pair(i-1,j-2));
	}
	if(i+2<8 && j+1<8)
	{
		if((s[i+2][j+1]=='.' || (s[i+2][j+1]>=65 && s[i+2][j+1]<=90 ))) ord.push_back(make_pair(i+2,j+1));
	}
	if(i+2<8 && j-1>=0)
	{
		if((s[i+2][j-1]=='.' || (s[i+2][j-1]>=65 && s[i+2][j-1]<=90 ))) ord.push_back(make_pair(i+2,j-1));
	}
	if(i-2>=0 && j+1<8)
	{
		if((s[i-2][j+1]=='.' || (s[i-2][j+1]>=65 && s[i-2][j+1]<=90 ))) ord.push_back(make_pair(i-2,j+1));
	}
	if(i-2>=0 && j-1>=0)
	{
		if((s[i-2][j-1]=='.' || (s[i-2][j-1]>=65 && s[i-2][j-1]<=90 ))) ord.push_back(make_pair(i-2,j-1));
	}
	return ord;
}
//QueenBlack
vector<pair<int,int>> OrdQueenBlack(int i,int j,state s)//complete
{
	vector<pair<int,int>> ord;
	ord=OrdCastleBlack(i,j,s);
	vector<pair<int,int>> copy;
	copy=OrdBishopBlack(i,j,s);
	for(int i=0;i<copy.size();i++)
	{
		ord.push_back(copy[i]);
	}
	return ord;
}
//GeneralBlack
vector<pair<int,int>> OrdGeneralBlack(int i,int j, state s)//COMPLETE
{
	vector<pair<int,int>> ord;
	if(i+1<8 && j+1<8)
	{
		if((s[i+1][j+1]=='.' || (s[i+1][j+1]>=65 && s[i+1][j+1]<=90 ))) ord.push_back(make_pair(i+1,j+1));
	}
	if(i+1<8 && j-1>=0)
	{
		if((s[i+1][j-1]=='.' || (s[i+1][j-1]>=65 && s[i+1][j-1]<=90 ))) ord.push_back(make_pair(i+1,j-1));
	}
	if(i-1>=0 && j+1<8)
	{
		if((s[i-1][j+1]=='.' || (s[i-1][j+1]>=65 && s[i-1][j+1]<=90 ))) ord.push_back(make_pair(i-1,j+1));
	}
	if(i-1>=0 && j-1>=0)
	{
		if((s[i-1][j-1]=='.' || (s[i-1][j-1]>=65 && s[i-1][j-1]<=90 ))) ord.push_back(make_pair(i-1,j-1));
	}

	if(i<8 && j+1<8)
	{
		if((s[i][j+1]=='.' || (s[i][j+1]>=65 && s[i][j+1]<=90 ))) ord.push_back(make_pair(i,j+1));
	}
	if(i<8 && j-1>=0)
	{
		if((s[i][j-1]=='.' || (s[i][j-1]>=65 && s[i][j-1]<=90 ))) ord.push_back(make_pair(i,j-1));
	}
	if(i-1>=0 && j<8)
	{
		if((s[i-1][j]=='.' || (s[i-1][j]>=65 && s[i-1][j]<=90 ))) ord.push_back(make_pair(i-1,j));
	}
	if(i+1<8 && j>=0)
	{
		if((s[i+1][j]=='.' || (s[i+1][j]>=65 && s[i+1][j]<=90 ))) ord.push_back(make_pair(i+1,j));
	}
	return ord;
}
//KingWhite
bool IsValidMoveOfKingWhite(int i,int j,int i1,int j1,state s)//complete***
{
	state newstate;
	newstate=s;
	newstate=Move(i,j,i1,j1,newstate);
	vector<pair<int,int>> neword;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			switch (newstate[i][j])
			{
				case 'p':
					neword=OrdPawnBlack(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				case 'c':
					neword=OrdCastleBlack(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				case 'b':
					neword=OrdBishopBlack(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				case 'k':
					neword=OrdKnightBlack(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				case 'q':
					neword=OrdQueenBlack(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				case 'g':
					neword=OrdGeneralBlack(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				default:
					break;
			}
		}
	}
	return true;
}
vector<pair<int,int>> OrdKingWhite(int i,int j, state s)//complete
{
	vector<pair<int,int>> ord;
	if(i+1<8 && j+1<8)
	{
		if((s[i+1][j+1]=='.' || (s[i+1][j+1]>=97 && s[i+1][j+1]<=122 )) && IsValidMoveOfKingWhite(i,j,i+1,j+1,s)) ord.push_back(make_pair(i+1,j+1));
	}
	if(i+1<8 && j-1>=0)
	{
		if((s[i+1][j-1]=='.' || (s[i+1][j-1]>=97 && s[i+1][j-1]<=122 )) && IsValidMoveOfKingWhite(i,j,i+1,j-1,s)) ord.push_back(make_pair(i+1,j-1));
	}
	if(i-1>=0 && j+1<8)
	{
		if((s[i-1][j+1]=='.' || (s[i-1][j+1]>=97 && s[i-1][j+1]<=122 )) && IsValidMoveOfKingWhite(i,j,i-1,j+1,s)) ord.push_back(make_pair(i-1,j+1));
	}
	if(i-1>=0 && j-1>=0)
	{
		if((s[i-1][j-1]=='.' || (s[i-1][j-1]>=97 && s[i-1][j-1]<=122 )) && IsValidMoveOfKingWhite(i,j,i-1,j-1,s)) ord.push_back(make_pair(i-1,j-1));
	}
	if(i<8 && j+1<8)
	{
		if((s[i][j+1]=='.' || (s[i][j+1]>=97 && s[i][j+1]<=122 )) && IsValidMoveOfKingWhite(i,j,i,j+1,s)) ord.push_back(make_pair(i,j+1));
	}
	if(i<8 && j-1>=0)
	{
		if((s[i][j-1]=='.' || (s[i][j-1]>=97 && s[i][j-1]<=122 )) && IsValidMoveOfKingWhite(i,j,i,j-1,s)) ord.push_back(make_pair(i,j-1));
	}
	if(i-1>=0 && j<8)
	{
		if((s[i-1][j]=='.' || (s[i-1][j]>=97 && s[i-1][j]<=122 )) && IsValidMoveOfKingWhite(i,j,i-1,j,s)) ord.push_back(make_pair(i-1,j));
	}
	if(i+1>=0 && j>=0)
	{
		if((s[i+1][j]=='.' || (s[i+1][j]>=97 && s[i+1][j]<=122 )) && IsValidMoveOfKingWhite(i,j,i+1,j,s)) ord.push_back(make_pair(i+1,j));
	}
	return ord;
}
//KingBlack
bool IsValidMoveOfKingBlack(int i,int j,int i1,int j1,state s)//complete
{
	state newstate;
	newstate=s;
	newstate=Move(i,j,i1,j1,newstate);
	vector<pair<int,int>> neword;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			switch (newstate[i][j])
			{
				case 'P':
					neword=OrdPawnWhite(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				case 'C':
					neword=OrdCastleWhite(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				case 'B':
					neword=OrdBishopWhite(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				case 'K':
					neword=OrdKnightWhite(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				case 'Q':
					neword=OrdQueenWhite(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				case 'G':
					neword=OrdGeneralWhite(i,j,newstate);
					for(int k=0;k<neword.size();k++)
					{
						if(neword[k].first==i1 && neword[k].second==j1)
						return false;
					}
					break;
				default:
					break;
			}
		}
	}
	return true;
}
vector<pair<int,int>> OrdKingBlack(int i,int j, state s)//complete
{
	vector<pair<int,int>> ord;
	if(i+1<8 && j+1<8)
	{
		if((s[i+1][j+1]=='.' || (s[i+1][j+1]>=65 && s[i+1][j+1]<=90 )) && IsValidMoveOfKingBlack(i,j,i+1,j+1,s)) ord.push_back(make_pair(i+1,j+1));
	}
	if(i+1<8 && j-1>=0)
	{
		if((s[i+1][j-1]=='.' || (s[i+1][j-1]>=65 && s[i+1][j-1]<=90 )) && IsValidMoveOfKingBlack(i,j,i+1,j-1,s)) ord.push_back(make_pair(i+1,j-1));
	}
	if((i-1>=0 && j+1<8))
	{
		if((s[i-1][j+1]=='.' || (s[i-1][j+1]>=65 && s[i-1][j+1]<=90 )) && IsValidMoveOfKingBlack(i,j,i-1,j+1,s)) ord.push_back(make_pair(i-1,j+1));
	}
	if(i-1>=0 && j-1>=0)
	{
		if((s[i-1][j-1]=='.' || (s[i-1][j-1]>=65 && s[i-1][j-1]<=90 )) && IsValidMoveOfKingBlack(i,j,i-1,j-1,s)) ord.push_back(make_pair(i-1,j-1));
	}
	if(i<8 && j+1<8)
	{
		if((s[i][j+1]=='.' || (s[i][j+1]>=65 && s[i][j+1]<=90 )) && IsValidMoveOfKingBlack(i,j,i,j+1,s)) ord.push_back(make_pair(i,j+1));
	}
	if(i<8 && j-1>=0)
	{
		if((s[i][j-1]=='.' || (s[i][j-1]>=65 && s[i][j-1]<=90 )) && IsValidMoveOfKingBlack(i,j,i,j-1,s)) ord.push_back(make_pair(i,j-1));
	}
	if(i-1>=0 && j<8)
	{
		if((s[i-1][j]=='.' || (s[i-1][j]>=65 && s[i-1][j]<=90 )) && IsValidMoveOfKingBlack(i,j,i-1,j,s)) ord.push_back(make_pair(i-1,j));
	}
	if(i+1<8 && j>=0)
	{
		if((s[i+1][j]=='.' || (s[i+1][j]>=65 && s[i+1][j]<=90 )) && IsValidMoveOfKingBlack(i,j,i+1,j,s)) ord.push_back(make_pair(i+1,j));
	}
	return ord;
}

vector<state> GetNextStateWhite(state s)//complete
{
	vector<state> nextstate;
	vector<pair<int,int>> neword;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			switch (s[i][j])
			{
				case 'P':
					neword=OrdPawnWhite(i,j,s);
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				case 'C':
					neword=OrdCastleWhite(i,j,s);
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				case 'B':
					neword=OrdBishopWhite(i,j,s);
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				case 'K':
					neword=OrdKnightWhite(i,j,s);
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				case 'Q':
					neword=OrdQueenWhite(i,j,s);
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				case 'G':
					neword=OrdKingWhite(i,j,s);
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				default:
					break;
			}
		}
	}
	return nextstate;
}
vector<state> GetNextStateBlack(state s)//complete
{
	vector<state> nextstate;
	vector<pair<int,int>> neword;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			switch (s[i][j])
			{
				case 'p':
					neword=OrdPawnBlack(i,j,s);
					if(neword.size()!=0)
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				case 'c':
					neword=OrdCastleBlack(i,j,s);
					if(neword.size()!=0)
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				case 'b':
					neword=OrdBishopBlack(i,j,s);
					if(neword.size()!=0)
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				case 'k':
					neword=OrdKnightBlack(i,j,s);
					if(neword.size()!=0)
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				case 'q':
					neword=OrdQueenBlack(i,j,s);
					if(neword.size()!=0)
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				case 'g':
					neword=OrdKingBlack(i,j,s);
					if(neword.size()!=0)
					for(int k=0;k<neword.size();k++)
					{
						nextstate.push_back(Move(i,j,neword[k].first,neword[k].second,s));
					}
					break;
				default:
					break;
			}
		}
	}
	return nextstate;
}

vector<state> GetNextState(state s,bool IsMoveOfWhite)//complete
{
	if(IsMoveOfWhite)
	return GetNextStateWhite(s);
	else
	return GetNextStateBlack(s);
}
bool IsFinalStateWhite(state s)//White lost; min complete
{
	int y,x;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(s[i][j]=='G')
			{
				return false;
			}
		}
	}
	return true;
}
bool IsFinalStateWhiteDraw(state s)//complete
{
	vector<state> vs=GetNextStateWhite(s);
	if(vs.size()==0)
	return true;
	return false;
}
bool IsFinalStateBlackDraw(state s)//complete
{
	vector<state> vs=GetNextStateBlack(s);
	if(vs.size()==0)
	return true;
	return false;
}
bool IsFinalStateDraw(state s)//,bool IsMoveOfWhite) complete
{
	return IsFinalStateWhiteDraw(s) || IsFinalStateBlackDraw(s);
}
bool IsFinalStateBlack(state s)// Black Lost, White win, max complete
{
	int y,x;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(s[i][j]=='g')
			{
				return false;
			}
		}
	}
	return true;
}
bool IsFinalStateWin(state s)//complete
{
	return IsFinalStateWhite(s) || IsFinalStateBlack(s);
}
bool IsFinalState(state s)//complete
{
	return IsFinalStateWin(s) || IsFinalStateDraw(s);
}
//GetScoreMiddleStateOfOrdinate
vector<vector<double>> ScoreOrdinateWhite(char chessman)
{
	vector<vector<double>> s(8,vector<double>(8));
	switch (chessman)
	{
		//white
		case 'P'://pawnwhite
			s[0][0]= 0;s[0][1]= 0;s[0][2]= 0;s[0][3]= 0;s[0][4]= 0;s[0][5]= 0;s[0][6]= 0;s[0][7]= 0;
			s[1][0]= 0.5;s[1][1]= 1;s[1][2]= 1;s[1][3]= -2;s[1][4]= -2;s[1][5]= 1;s[1][6]= 1;s[1][7]= 0.5;
			s[2][0]= 0.5;s[2][1]= -0.5;s[2][2]= -1.0;s[2][3]= 0;s[2][4]= 0;s[2][5]= -1;s[2][6]= -0.5;s[2][7]= 0.5;
			s[3][0]= 0;s[3][1]= 0;s[3][2]= 0;s[3][3]= 2;s[3][4]= 2;s[3][5]= 0;s[3][6]= 0;s[3][7]= 0;
			s[4][0]= 0.5;s[4][1]= 0.5;s[4][2]= 1;s[4][3]= 2.5;s[4][4]= 2.5;s[4][5]= 1;s[4][6]= 0.5;s[4][7]= 0.5;
			s[5][0]= 1;s[5][1]= 1;s[5][2]= 2;s[5][3]= 3;s[5][4]= 3;s[5][5]= 2;s[5][6]= 1;s[5][7]= 1;
			s[6][0]= 5;s[6][1]= 5;s[6][2]= 5;s[6][3]= 5;s[6][4]= 5;s[6][5]= 5;s[6][6]= 5;s[6][7]= 5;
			s[7][0]= 0;s[7][1]= 0;s[7][2]= 0;s[7][3]= 0;s[7][4]= 0;s[7][5]= 0;s[7][6]= 0;s[7][7]= 0;
			break;
		case 'K':
			s[0][0]= -5;s[0][1]= -4;s[0][2]= -3;s[0][3]= -3;s[0][4]= -3;s[0][5]= -3;s[0][6]= -4;s[0][7]= -5;
			s[1][0]= -4;s[1][1]= -2;s[1][2]= 0;s[1][3]= 0.5;s[1][4]= 0.5;s[1][5]= 0;s[1][6]= -2;s[1][7]= -4;
			s[2][0]= -3;s[2][1]= 0.5;s[2][2]= 1;s[2][3]= 1.5;s[2][4]= 1.5;s[2][5]= 1;s[2][6]= 0.5;s[2][7]= -3;
			s[3][0]= -3;s[3][1]= 0;s[3][2]= 1.5;s[3][3]= 2;s[3][4]= 2;s[3][5]= 1.5;s[3][6]= 0;s[3][7]= -3;
			s[4][0]= -3;s[4][1]= 0.5;s[4][2]= 1.5;s[4][3]= 2;s[4][4]= 2;s[4][5]= 1.5;s[4][6]= 0.5;s[4][7]= -3;
			s[5][0]= -3;s[5][1]= 0;s[5][2]= 1;s[5][3]= 1.5;s[5][4]= 1.5;s[5][5]= 1;s[5][6]= 0;s[5][7]= -3;
			s[6][0]= -4;s[6][1]= -2;s[6][2]= 0;s[6][3]= 0;s[6][4]= 0;s[6][5]= 0;s[6][6]= -2;s[6][7]= -4;
			s[7][0]= -5;s[7][1]= -4;s[7][2]= -3;s[7][3]= -3;s[7][4]= -3;s[7][5]= -3;s[7][6]= -4;s[7][7]= -5;
			break;
		case 'B':
			s[0][0]= -2;s[0][1]= -1;s[0][2]= -1;s[0][3]= -1;s[0][4]= -1;s[0][5]= -1;s[0][6]= -1;s[0][7]= -2;
			s[1][0]= -1;s[1][1]= 0.5;s[1][2]= 0;s[1][3]= 0;s[1][4]= 0;s[1][5]= 0;s[1][6]= 0.5;s[1][7]= -1;
			s[2][0]= -1;s[2][1]= 1;s[2][2]= 1;s[2][3]= 1;s[2][4]= 1;s[2][5]= 1;s[2][6]= 1;s[2][7]= -1;
			s[3][0]= -1;s[3][1]= 0;s[3][2]= 1;s[3][3]= 1;s[3][4]= 1;s[3][5]= 1;s[3][6]= 0;s[3][7]= -1;
			s[4][0]= -1;s[4][1]= 0.5;s[4][2]= 0.5;s[4][3]= 1;s[4][4]= 1;s[4][5]= 0.5;s[4][6]= 0.5;s[4][7]= -1;
			s[5][0]= -1;s[5][1]= 0;s[5][2]= 0.5;s[5][3]= 1;s[5][4]= 1;s[5][5]= 0.5;s[5][6]= 0;s[5][7]= -1;
			s[6][0]= -1;s[6][1]= 0;s[6][2]= 0;s[6][3]= 0;s[6][4]= 0;s[6][5]= 0;s[6][6]= 0;s[6][7]= -1;
			s[7][0]= -2;s[7][1]= -1;s[7][2]= -1;s[7][3]= -1;s[7][4]= -1;s[7][5]= -1;s[7][6]= -1;s[7][7]= -2;
			break;
		case 'C':
			s[0][0]= 0;s[0][1]= 0;s[0][2]= 0;s[0][3]= 0.5;s[0][4]= 0.5;s[0][5]= 0;s[0][6]= 0;s[0][7]= 0;
			s[1][0]= -0.5;s[1][1]= 0;s[1][2]= 0;s[1][3]= 0;s[1][4]= 0;s[1][5]= 0;s[1][6]= 0;s[1][7]= -0.5;
			s[2][0]= -0.5;s[2][1]= 0;s[2][2]= 0;s[2][3]= 0;s[2][4]= 0;s[2][5]= 0;s[2][6]= 0;s[2][7]= -0.5;
			s[3][0]= -0.5;s[3][1]= 0;s[3][2]= 0;s[3][3]= 0;s[3][4]= 0;s[3][5]= 0;s[3][6]= 0;s[3][7]= -0.5;
			s[4][0]= -0.5;s[4][1]= 0;s[4][2]= 0;s[4][3]= 0;s[4][4]= 0;s[4][5]= 0;s[4][6]= 0;s[4][7]= -0.5;
			s[5][0]= -0.5;s[5][1]= 0;s[5][2]= 0;s[5][3]= 0;s[5][4]= 0;s[5][5]= 0;s[5][6]= 0;s[5][7]= -0.5;
			s[6][0]= 0.5;s[6][1]= 1;s[6][2]= 1;s[6][3]= 1;s[6][4]= 1;s[6][5]= 1;s[6][6]= 1;s[6][7]= 0.5;
			s[7][0]= 0;s[7][1]= 0;s[7][2]= 0;s[7][3]= 0;s[7][4]= 0;s[7][5]= 0;s[7][6]= 0;s[7][7]= 0;
			break;
		case 'Q':
			s[0][0]= -2;s[0][1]= -1;s[0][2]= -1;s[0][3]= -0.5;s[0][4]= -0.5;s[0][5]= -1;s[0][6]= -1;s[0][7]= -2;
			s[1][0]= -1;s[1][1]= 0;s[1][2]= 0.5;s[1][3]= 0;s[1][4]= 0;s[1][5]= 0;s[1][6]= 0;s[1][7]= -1;
			s[2][0]= -1;s[2][1]= 0.5;s[2][2]= 0.5;s[2][3]= 0.5;s[2][4]= 0.5;s[2][5]= 0.5;s[2][6]= 0;s[2][7]= -1;
			s[3][0]= 0;s[3][1]= 0;s[3][2]= 0.5;s[3][3]= 0.5;s[3][4]= 0.5;s[3][5]= 0.5;s[3][6]= 0;s[3][7]= -0.5;
			s[4][0]= -0.5;s[4][1]= 0;s[4][2]= 0.5;s[4][3]= 0.5;s[4][4]= 0.5;s[4][5]= 0.5;s[4][6]= 0;s[4][7]= -0.5;
			s[5][0]= -1;s[5][1]= 0;s[5][2]= 0.5;s[5][3]= 0.5;s[5][4]= 0.5;s[5][5]= 0.5;s[5][6]= 0;s[5][7]= -1;
			s[6][0]= -1;s[6][1]= 0;s[6][2]= 0;s[6][3]= 0;s[6][4]= 0;s[6][5]= 0;s[6][6]= 0;s[6][7]= -1;
			s[7][0]= -2;s[7][1]= -1;s[7][2]= -1;s[7][3]= -0.5;s[7][4]= -0.5;s[7][5]= -1;s[7][6]= -1;s[7][7]= -2;
			break;
		case 'G':
			s[0][0]= 2;s[0][1]= 3;s[0][2]= 1;s[0][3]= 0;s[0][4]= 0;s[0][5]= 2;s[0][6]= 3;s[0][7]= 1;
			s[1][0]= 2;s[1][1]= 2;s[1][2]= 0;s[1][3]= 0;s[1][4]= 0;s[1][5]= 0;s[1][6]= 2;s[1][7]= 2;
			s[2][0]= -1;s[2][1]= -2;s[2][2]= -2;s[2][3]= -2;s[2][4]= -2;s[2][5]= -2;s[2][6]= -2;s[2][7]= -1;
			s[3][0]= -2;s[3][1]= -3;s[3][2]= -3;s[3][3]= -4;s[3][4]= -4;s[3][5]= -3;s[3][6]= -3;s[3][7]= -2;
			s[4][0]= -3;s[4][1]= -4;s[4][2]= -4;s[4][3]= -5;s[4][4]= -5;s[4][5]= -4;s[4][6]= -4;s[4][7]= -3;
			s[5][0]= -3;s[5][1]= -4;s[5][2]= -4;s[5][3]= -5;s[5][4]= -5;s[5][5]= -4;s[5][6]= -4;s[5][7]= -3;
			s[6][0]= -3;s[6][1]= -4;s[6][2]= -4;s[6][3]= -5;s[6][4]= -5;s[6][5]= -4;s[6][6]= -4;s[6][7]= -3;
			s[7][0]= -3;s[7][1]= -4;s[7][2]= -4;s[7][3]= -5;s[7][4]= -5;s[7][5]= -4;s[7][6]= -4;s[7][7]= -3;
			break;
		default:
			break;

	}
	return s;
}
vector<vector<double>> ScoreOrdinateBlack(char chessman)
{
	vector<vector<double>> sB(8,vector<double>(8));
	vector<vector<double>> sW(8,vector<double>(8));
	switch (chessman)
	{
		case 'p':
			sW=ScoreOrdinateWhite('P');
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					sB[i][j]=-sW[7-i][j];
				}
			}
			break;
		case 'k':
			sW=ScoreOrdinateWhite('K');
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					sB[i][j]=-sW[7-i][j];
				}
			}
			break;
		case 'c':
			sW=ScoreOrdinateWhite('C');
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					sB[i][j]=-sW[7-i][j];
				}
			}
			break;
		case 'b':
			sW=ScoreOrdinateWhite('B');
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					sB[i][j]=-sW[7-i][j];
				}
			}
			break;
		case 'q':
			sW=ScoreOrdinateWhite('Q');
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					sB[i][j]=-sW[7-i][j];
				}
			}
			break;
		case 'g':
			sW=ScoreOrdinateWhite('G');
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					sB[i][j]=-sW[7-i][j];
				}
			}
			break;
		default :
			break;
	}
	return sB;
}
vector<vector<double>> ScoreOrdinate(char chessman)
{
	vector<vector<double>> s(8,vector<double>(8));
	if(chessman>=65 && chessman<=90)
	{
		s=ScoreOrdinateWhite(chessman);
	}
	else
	{
		s=ScoreOrdinateBlack(chessman);
	}
	return s;
}
int ScoreOfOrdinate(int i,int j,char chessman)
{
	vector<vector<double>> s(8,vector<double>(8));
	s=ScoreOrdinate(chessman);
	return s[i][j];
}
int GetScoreFinalState(state s)//final state complete
{
	if(IsFinalStateWhite(s))
	{
		return -100;
	}
	else
	{
		if(IsFinalStateBlack(s))
		{
			return 100;
		}
		else
		{
			if(IsFinalStateDraw(s))
			{
				return 0;
			}

		}
	}
	return 0;
}
int CountAliveChessman(char c, state s)//complete
{
	int count=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(s[i][j]==c)
			count++;
		}
	}
	return count;
}
/*int GetScoreMiddleStateWhite(state s)//complete
{
	int a=0;
	a+=(8-CountAliveChessman('p',s))*10;
	a+=(2-CountAliveChessman('c',s))*50;
	a+=(2-CountAliveChessman('b',s))*30;
	a+=(2-CountAliveChessman('k',s))*30;
	a+=(1-CountAliveChessman('q',s))*90;
	return a;
}
int GetScoreMiddleStateBlack(state s)//complete
{
	int a=0;
	a-=(8-CountAliveChessman('P',s))*10;
	a-=(2-CountAliveChessman('C',s))*50;
	a-=(2-CountAliveChessman('B',s))*30;
	a-=(2-CountAliveChessman('K',s))*30;
	a-=(1-CountAliveChessman('Q',s))*90;
	return a;
}*/
double GetScoreMiddleState(state s)
{
	double Score=0;
	double ScoreOrd=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			switch (s[i][j])
			{
				//White
				case 'P':
					ScoreOrd=ScoreOfOrdinate(i,j,'P');
					Score=Score+10+ScoreOrd;
					break;
				case 'B':
					ScoreOrd=ScoreOfOrdinate(i,j,'B');
					Score=Score+30+ScoreOrd;
					break;
				case 'K':
					ScoreOrd=ScoreOfOrdinate(i,j,'K');
					Score=Score+30+ScoreOrd;
					break;
				case 'C':
					ScoreOrd=ScoreOfOrdinate(i,j,'C');
					Score=Score+50+ScoreOrd;
					break;
				case 'Q':
					ScoreOrd=ScoreOfOrdinate(i,j,'Q');
					Score=Score+90+ScoreOrd;
					break;
				//Black
				case 'p':
					ScoreOrd=ScoreOfOrdinate(i,j,'p');
					Score=Score-10+ScoreOrd;
					break;
				case 'b':
					ScoreOrd=ScoreOfOrdinate(i,j,'b');
					Score=Score-30+ScoreOrd;
					break;
				case 'k':
					ScoreOrd=ScoreOfOrdinate(i,j,'k');
					Score=Score-30+ScoreOrd;
					break;
				case 'c':
					ScoreOrd=ScoreOfOrdinate(i,j,'c');
					Score=Score-50+ScoreOrd;
					break;
				case 'q':
					ScoreOrd=ScoreOfOrdinate(i,j,'q');
					Score=Score-90+ScoreOrd;
			}
		}
	}
	return Score;
}


/*int GetScoreMiddleStateOfOrdinate(state s)// truyền vào nextstate
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(s[i][j]!='.')
			{

			}
		}
	}
}*/
//getScoreSquare
pair<int,int> GetScoreSquare(int I,int J,state s)
{
	vector<pair<int,int>> ord;
	int ScoreW=0;
	int ScoreB=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			switch (s[i][j])
			{
				//White
				case 'P':
					ord=OrdPawnWhitePro(i,j,s);
					for(int k=0;k<ord.size();k++)
					{
						if(ord[k].first==I && ord[k].second==J)
						{
							ScoreW+=9;
						}
					}
					break;
				case 'C':
					ord=OrdCastleWhite(i,j,s);
					for(int k=0;k<ord.size();k++)
					{
						if(ord[k].first==I && ord[k].second==J)
						{
							ScoreW+=3;
						}
					}
					break;
				case 'B':
					ord=OrdBishopWhite(i,j,s);
					for(int k=0;k<ord.size();k++)
					{
						if(ord[k].first==I && ord[k].second==J)
						{
							ScoreW+=5;
						}
					}
					break;
				case 'K':
					ord=OrdKnightWhite(i,j,s);
					for(int k=0;k<ord.size();k++)
					{
						if(ord[k].first==I && ord[k].second==J)
						{
							ScoreW+=5;
						}
					}
					break;
				case 'Q':
					ord=OrdQueenWhite(i,j,s);
					for(int k=0;k<ord.size();k++)
					{
						if(ord[k].first==I && ord[k].second==J)
						{
							ScoreW+=1;
						}
					}
					break;
					//Black
				case 'p':
					ord=OrdPawnBlackPro(i,j,s);
					for(int k=0;k<ord.size();k++)
					{
						if(ord[k].first==I && ord[k].second==J)
						{
							ScoreB-=9;
						}
					}
					break;
				case 'c':
					ord=OrdCastleBlack(i,j,s);
					for(int k=0;k<ord.size();k++)
					{
						if(ord[k].first==I && ord[k].second==J)
						{
							ScoreB-=3;
						}
					}
					break;
				case 'b':
					ord=OrdBishopBlack(i,j,s);
					for(int k=0;k<ord.size();k++)
					{
						if(ord[k].first==I && ord[k].second==J)
						{
							ScoreB-=5;
						}
					}
					break;
				case 'k':
					ord=OrdKnightBlack(i,j,s);
					for(int k=0;k<ord.size();k++)
					{
						if(ord[k].first==I && ord[k].second==J)
						{
							ScoreB-=5;
						}
					}
					break;
				case 'q':
					ord=OrdQueenBlack(i,j,s);
					for(int k=0;k<ord.size();k++)
					{
						if(ord[k].first==I && ord[k].second==J)
						{
							ScoreB-=1;
						}
					}
					break;
				default:
					break;
			}
		}
	}
	return make_pair(ScoreW,ScoreB);
}

/*int GetScoreMiddleState(state s)//complete
{
	int a=0;
	a+=GetScoreMiddleStateWhite(s);
	a+=GetScoreMiddleStateBlack(s);
	return a;
}*/
//check stupid move: đi vào những ô có điểm số bất lợi
/*bool StupidMoveValueSquare(state s,state ns)
{
	pair<int,int> Score;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{

		}
	}
}*/
// check stupid move
/*bool StupidMove(vector<state> StateMoved, state s,state ns)
{
	int a=StateMoved.size();
	pair<int,int> before;//ordinate state s
	pair<int,int> after;//ordinate state ns
	pair<int,int> beforeM;//ordinate state moved
	pair<int,int> afterM;//ordinate state moved
	state SMn3=StateMoved[a-3];
	state SMn2=StateMoved[a-2];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(s[i][j]!='.'&& ns[i][j]=='.' )
			{
				before=make_pair(i,j);
			}
			if(s[i][j]=='.' && ns[i][j]!='.')
			{
				after=make_pair(i,j);
			}
			// đã đi nước có tọa độ before đến tọa độ after
			if(SMn3[i][j]!='.'&& SMn2[i][j]=='.' )
			{
				beforeM=make_pair(i,j);
			}
			if(SMn3[i][j]=='.' && SMn2[i][j]!='.')
			{
				afterM=make_pair(i,j);
			}
			//lượt đi liền trước của cùng 1 loại quân cờ
		}
	}
	if(afterM.first==before.first && afterM.second==before.second)
	{
		switch (s[beforeM.first][beforeM.second])
		{
			//White
			case 'P':
				vector<pair<int,int> arr=OrdPawnWhite(beforeM.first,beforeM.second,SMn3);
				int n=arr.size();
				for(int i=0;i<n;i++)
				{
					if(afterM.first==arr[i].first && afterM.second==arr[i].second)
					{
						return true;
					}
				}
				break;
 			case 'C':
 				vector<pair<int,int> arr=OrdCastleWhite(beforeM.first,beforeM.second,SMn3);
				int n=arr.size();
				for(int i=0;i<n;i++)
				{
					if(afterM.first==arr[i].first && afterM.second==arr[i].second)
					{
						return true;
					}
				}
				break;
			case 'B':
				vector<pair<int,int> arr=OrdBishopWhite(beforeM.first,beforeM.second,SMn3);
				int n=arr.size();
				for(int i=0;i<n;i++)
				{
					if(afterM.first==arr[i].first && afterM.second==arr[i].second)
					{
						return true;
					}
				}
				break;
			case 'K':
				vector<pair<int,int> arr=OrdKnightWhite(beforeM.first,beforeM.second,SMn3);
				int n=arr.size();
				for(int i=0;i<n;i++)
				{
					if(afterM.first==arr[i].first && afterM.second==arr[i].second)
					{
						return true;
					}
				}
				break;
			case 'Q':
				vector<pair<int,int> arr=OrdQueenWhite(beforeM.first,beforeM.second,SMn3);
				int n=arr.size();
				for(int i=0;i<n;i++)
				{
					if(afterM.first==arr[i].first && afterM.second==arr[i].second)
					{
						return true;
					}
				}
				break;
			//Black
			case 'p':
				vector<pair<int,int> arr=OrdPawnBlack(beforeM.first,beforeM.second,SMn3);
				int n=arr.size();
				for(int i=0;i<n;i++)
				{
					if(afterM.first==arr[i].first && afterM.second==arr[i].second)
					{
						return true;
					}
				}
				break;
 			case 'c':
 				vector<pair<int,int> arr=OrdCastleBlack(beforeM.first,beforeM.second,SMn3);
				int n=arr.size();
				for(int i=0;i<n;i++)
				{
					if(afterM.first==arr[i].first && afterM.second==arr[i].second)
					{
						return true;
					}
				}
				break;
			case 'b':
				vector<pair<int,int> arr=OrdBishopBlack(beforeM.first,beforeM.second,SMn3);
				int n=arr.size();
				for(int i=0;i<n;i++)
				{
					if(afterM.first==arr[i].first && afterM.second==arr[i].second)
					{
						return true;
					}
				}
				break;
			case 'k':
				vector<pair<int,int> arr=OrdKnightBlack(beforeM.first,beforeM.second,SMn3);
				int n=arr.size();
				for(int i=0;i<n;i++)
				{
					if(afterM.first==arr[i].first && afterM.second==arr[i].second)
					{
						return true;
					}
				}
				break;
			case 'q':
				vector<pair<int,int> arr=OrdQueenBlack(beforeM.first,beforeM.second,SMn3);
				int n=arr.size();
				for(int i=0;i<n;i++)
				{
					if(afterM.first==arr[i].first && afterM.second==arr[i].second)
					{
						return true;
					}
				}
				break;
			default:
				break;
		}
	}
	return false;
}*/
//thuật toán minmax, alpha beta , độ sâu depth, 1 số nước đi khai cuộc
//white: maximer Black: minimer
bool maximer()
{
	return true;
}
void ComputerMove(state s,state ns,int &i1,int &j1,int &i2,int &j2,char &c )
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(s[i][j]=='.' && ns[i][j]!='.')//luc sau
			{
				i2=i;j2=j;
				c=ns[i][j];
				switch(c)
				{
					case 'K':c='N';break;
					case 'k':c='n';break;
					case 'g':c='k';break;
					case 'G':c='K';break;
					default:break;
				}
			}
			if(s[i][j]!='.' && ns[i][j]=='.')//luc dau
			{
				i1=i;j1=j;
			}
		}
	}
}

// pair<int,state> GetScore(int depth,bool maximer,state s)//complete
// {
// 	if(IsFinalState(s) || depth==0)
// 	{
// 		if(IsFinalState(s))
// 		return make_pair(GetScoreFinalState(s),s);
// 		if(depth==0)
// 		return make_pair(GetScoreMiddleState(s),s);
// 	}
// 	bool IsMoveOfWhite=maximer;
// 	vector<state> states=GetNextState(s,IsMoveOfWhite);
// 	state beststate;
// 	int max=-10000;
// 	int min=10000;
// 	if(maximer)
// 	{
// 		for(state ns:states)
// 		{
// 			pair<int,state> np=GetScore(depth-1,false,ns);
// 			if( max<np.first )
// 			{
// 				max=np.first;
// 				beststate=ns;
// 			}
// 			if(max>min)
// 			{
// 				break;
// 			}
// 		}
// 		return make_pair(max,beststate)	;
// 	}
// 	else
// 	{
// 		for(state ns:states)
// 		{
// 			pair<int,state> np=GetScore(depth-1,true,ns);
// 			if( min>np.first )
// 			{
// 				min=np.first;
// 				beststate=ns;
// 			}
// 			if(max<=min)
// 			{
// 				break;
// 			}
// 		}
// 		return make_pair(min,beststate)	;
// 	}
// }
pair<int,state> GetScore(int depth,int alpha, int beta,bool maximer,state s)//complete
{
	if(IsFinalState(s) || depth==0)
	{
		if(IsFinalState(s))
		return make_pair(GetScoreFinalState(s),s);
		if(depth==0)
		return make_pair(GetScoreMiddleState(s),s);
	}
	bool IsMoveOfWhite=maximer;
	vector<state> states=GetNextState(s,IsMoveOfWhite);
	state beststate;
	int value;
	if(maximer)
	{
		value = int(-1e9);
		for(state ns:states)
		{
			pair<int,state> np=GetScore(depth-1,alpha,beta,false,ns);
			if( value<np.first )
			{
				value=np.first;
				beststate=ns;
			}
			if(value >= beta)
			{
				break;
			}
			alpha = max(alpha, value);
		}
	}
	else
	{
		value = int(1e9);
		for(state ns:states)
		{
			pair<int,state> np=GetScore(depth-1,alpha,beta,true,ns);
			if( value>np.first )
			{
				value=np.first;
				beststate=ns;
			}
			if(value <= alpha)
			{
				break;
			}
			beta = min(beta, value);
		}
	}
	return make_pair(value,beststate);
}
int main()
{
	state s;
	s= FirstRenderGame();
	/*s[5][0]='C';
	s[0][3]='Q';
	s[2][2]='P';
	s[2][4]='K';
	s[4][4]='g';
	s[6][6]='k';*/
	printRenderGame(s);
	char* humanplayer=new char[10];
	const char* white="White";
	cout<<"please pick a kind of player you want:";
	cin>>humanplayer;
    bool ComputerPlayer;
	bool nextPlayer=true;
	int countmove=0;
	int depth;
	if(strcmp(humanplayer,white)==0)
	{
		ComputerPlayer=false;
	}
	else
	{
		ComputerPlayer=true;
	}
    while(true)
    {
    	if(nextPlayer==ComputerPlayer)
    	{
    		if(countmove<15)
    		{
    			depth=4;
			}
			else
			{
				depth=8;
			}
    		int alpha = int(-1e9);
    		int beta = int(1e9);
    		pair<int,state> p=GetScore(depth,alpha,beta,ComputerPlayer,s);
    		int i1;int j1;int i2;int j2;char c;
    		ComputerMove(s,p.second,i1,j1,i2,j2,c);
    		cout<<"Created by MTM <3"<<endl;
			printRenderGame(p.second);
    	    cout<<" My move: "<<c<<'('<<char(i1+97)<<','<<j1+1<<')'<<"->"<<'('<<char(i2+97)<<','<<j2+1<<')';
			s=p.second;
			countmove++;
		}
    	else
    	{
    		int j,j1;
    		char i,i1;
    		cout<<" Your move:";
			cin>>i>>j>>i1>>j1;
    		s=Move(i-97,j-1,i1-97,j1-1,s);
    		printRenderGame(s);
    		cout<<"Created by MTM <3"<<endl;
    		countmove++;
		}
		nextPlayer=!nextPlayer;
		if(IsFinalState(s))
		{
			GetScoreFinalState(s)>0?cout<<"White":cout<<"Black";cout<<" Win";
			break;
		}
	}
	/*vector<state> arr;
	arr=GetNextStateWhite(s);
	for(int i=0;i<arr.size();i++)
	{
		printRenderGame(arr[i]);
	}
	//cout<<"....|....................";
	//cout<<GetScoreMiddleStateWhite(s);*/
	return 0;
}
/*int main()
{
	state s;
	s= FirstRenderGame();
	s[1][0]='P';
	//s[2][1]='c';
	//s[7][1]='q';
	printRenderGame(s);
	cout<<GetScoreMiddleState(s);
	return 0;
	//vector<vector<double>> s;

} */
