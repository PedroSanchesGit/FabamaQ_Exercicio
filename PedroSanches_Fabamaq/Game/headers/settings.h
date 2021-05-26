/* ***************************************************************  */
/* ********** Desafio Fabamaq ************************************  */
/* **                                                           **  */
/* ********** Autor: Pedro Sanches *******************************  */
/* **                                                           **  */
/* ********** Data Entrega: 15 outubro 2020 **********************  */
/* ***************************************************************  */
/* **  LINKEDIN : https://www.linkedin.com/in/pedro-ma-sanches/  ** */
/* ***************************************************************  */

#pragma once

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 2

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/Main Menu Background.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/Main Menu Background.png"
#define PAUSE_BACKGROUND_FILEPATH "Resources/res/Main Menu Background.png"

#define MAIN_MENU_TITLE_FILEPATH "Resources/res/Game Title.png"

#define MAIN_MENU_PLAY_BUTTON "Resources/res/Play Button.png"
#define RESUME_BUTTON "Resources/res/Resume Button.png"
#define HOME_BUTTON "Resources/res/Home Button.png"
#define RETRY_BUTTON "Resources/res/Retry Button.png"

#define MAIN_MENU_PLAY_BUTTON_OUTER "Resources/res/Play Button Outer.png"

#define START_BUTTON "Resources/res/Start Button.png"
#define PAUSE_BUTTON "Resources/res/Pause Button.png"
#define CREDITS_IN "Resources/res/Credits IN.png"
#define CREDITS_OUT "Resources/res/Credits OUT.png"

#define X_PIECE_FILEPATH "Resources/res/X.png"
#define O_PIECE_FILEPATH "Resources/res/O.png"
#define TRIANGULO_PIECE_FILEPATH "Resources/res/Triangulo.png"
#define SQUARE_PIECE_FILEPATH "Resources/res/Square.png"
#define X_WINNING_PIECE_FILEPATH "Resources/res/X Win.png"
#define O_WINNING_PIECE_FILEPATH "Resources/res/O Win.png"
#define TRIANGULO_WINNING_PIECE_FILEPATH "Resources/res/Triangulo Win.png"
#define SQUARE_WINNING_PIECE_FILEPATH "Resources/res/Square Win.png"

#define GRID_SPRITE_FILEPATH "Resources/res/Grid.png"

#define MYFONT "Resources/fonts/Marker Felt.ttf"

#define X_PIECE 8
#define O_PIECE 0
#define TRIANGULO_PIECE 4
#define SQUARE_PIECE 2
#define EMPTY_PIECE -1
#define PLAYER_PIECE SQUARE_PIECE //change if you want to try other piece

#define STATE_WAITING 99
#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94

#define TIME_BEFORE_SHOWING_GAME_OVER 3

