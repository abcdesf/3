#include <iostream>
#include <cstdio>
#include <ctime>
#include "search_engine.h"
#include "time.h"
#include "tools.h"
using namespace std;
// Main function for the app, taking the first argument as the Engine's name.
CSearchEngine searchEngine;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    char board[GRID_NUM][GRID_NUM]={0};
    move_t m_best_move; 
    int x, y;
	for(int i = 0; i< 19 ; i++)
    {
        board[i][0] = board[0][i] = board[i][GRID_NUM-1] = board[GRID_NUM-1][i] = BORDER;
    }
    for(int i = 1 ; i< GRID_NUM-1 ; i++)
    {
        for(int j = 1 ; j < GRID_NUM-1 ; j++)
        {
            board[i][j] = NOSTONE;
        }
    }
    // Initialize the board with black pieces
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        board[x][y] = BLACK;
        if(n==1){
    		m_best_move.positions[0].x = m_best_move.positions[1].x = x;
    		m_best_move.positions[0].y = m_best_move.positions[1].y = y;
		}else{
			if(i==n-2&&k==2){
				m_best_move.positions[0].x = x;
				m_best_move.positions[0].y = y;
			}
			if(i==n-1&&k==2){
				m_best_move.positions[1].x = x;
				m_best_move.positions[1].y = y;
			}
		}
    }
    // Initialize the board with white pieces
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        board[x][y] = WHITE;
        if(i==n-2&&k==1){
			m_best_move.positions[0].x = x;
			m_best_move.positions[0].y = y;
		}
		if(i==n-1&&k==1){
			m_best_move.positions[1].x = x;
			m_best_move.positions[1].y = y;
		}
    } 
    char ourColor = (k == 2) ? WHITE : BLACK;
//    vcf_search.init(); 
	int m_alphabeta_depth = 6;
    if (k == 0) {
    	board[9][9]=BLACK;
    	m_best_move.positions[0].x = m_best_move.positions[1].x = 9;
    	m_best_move.positions[0].y = m_best_move.positions[1].y = 9;
    	m_best_move.score = 0;
        cout << 9 << " " << 9;
    	return 0;
    } else {
    	if(n==1&&m==0&&board[9][9]==BLACK){
    		board[9][10]=WHITE;
    		board[10][9]=WHITE;
    		m_best_move.positions[0].x = 9;
    		m_best_move.positions[0].y = 10;
    		m_best_move.positions[1].x = 10;
    		m_best_move.positions[1].y = 9;
		}else if(n==1&&m==0&&board[9][9]!=BLACK){
			board[9][9]=WHITE;
			m_best_move.positions[0].x = 9;
    		m_best_move.positions[0].y = 9;
			if(board[10][8]!=BLACK)
    		{
			board[10][8]=WHITE;
    		m_best_move.positions[1].x = 10;
    		m_best_move.positions[1].y = 8;
    		}else{
    		board[10][10]=WHITE;
    		m_best_move.positions[1].x = 10;
    		m_best_move.positions[1].y = 10;
			}
		}
    	else
    	{
//    		vcf_search.before_search(board, ourColor);
//    		bool vcf= vcf_search.vcf_search(0,ourColor,&m_best_move,&m_best_move,0,-1);
//    		if(!vcf){
				initialize_timer();
				searchEngine.before_search(board, ourColor, m_alphabeta_depth); 
    			searchEngine.alpha_beta_search(m_alphabeta_depth, MININT, MAXINT, ourColor, &m_best_move, &m_best_move);
//    		}
    	}
        	cout << m_best_move.positions[0].x << " " << m_best_move.positions[0].y << " "
                  << m_best_move.positions[1].x << " " << m_best_move.positions[1].y;
    		return 0;
    }
}


