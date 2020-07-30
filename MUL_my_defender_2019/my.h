/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Include
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>

struct begin_m
{
    float scale;
    int size;
    float pos;
    sfText *text;
    sfFont  *font;
    sfSprite *sprite;
    sfTexture *texture;
};
typedef struct begin_m begin_m;
begin_m men[3];

struct start
{
    int status;
    int state;
    int text;
    sfClock *down;
    sfClock *cl;
    sfTexture *texture;
    sfTexture *t2;
    sfSprite *sprite;
    sfTexture *texture_p;
    sfSprite *sprite_p;
};
typedef struct start start;
start io;
struct towers
{
    int set;
    int on;
    int range;
    int speed;
    sfVector2f pos;
    sfTexture *text[4];
    sfSprite **sprite;
    sfClock *cl;
    sfTexture *shoptext;
    sfSprite *shop;
};
typedef struct towers towers;
towers tw[12];
struct user
{
    int money;
    int life;
    int score;
    sfText *piece[4];
    sfFont *font;
    sfTexture *text;
    sfSprite *heart[5];
};
typedef struct user user;
user us;
struct zomb1
{
    int hit;
    int dead;
    int poison;
    int speed;
    float life;
    int temp;
    int path;
    sfVector2f pos;
    sfClock *cl;
    sfTexture *text[16];
    sfSprite *z1;
};
typedef struct zomb1 zomb1;
zomb1 zo1[200];
struct zomb2
{
    int hit;
    int dead;
    int poison;
    float speed;
    float life;
    int temp;
    int path;
    sfVector2f pos;
    sfClock *cl;
    sfTexture *text[8];
    sfSprite *z2;
};
typedef struct zomb2 zomb2;
zomb2 zo2[50];
struct zomb3
{
    int hit;
    int dead;
    int poison;
    float speed;
    float life;
    int temp;
    int path;
    sfVector2f pos;
    sfClock *cl;
    sfTexture *text[12];
    sfSprite *z3;
};
typedef struct zomb3 zomb3;
zomb3 zo3[20];
struct att
{
    float speed;
    int set[50];
    int target[50];
    sfClock *cl;
    sfTexture *text[4];
    sfSprite *sprite;
    sfVector2f pos[50];
    int dgt;
};
typedef struct att att;
att ia[12];
struct how
{
    float scale;
    sfText *text[10];
    sfFont *font;
    int temp;
};
typedef struct how how;
how htp;
struct g_o
{
    float scale;
    int bouton;
    float pos[3];
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *cl;
    sfVector2f size[3];
    sfVector2f loc[3];
    sfText *text[3];
    sfFont *font;
    int temp;
    sfSoundBuffer *buff[5];
    sfSound *sound[5];
};
typedef struct g_o g_o;
g_o over;
void menu2(sfRenderWindow *window);
void menu(sfRenderWindow *window);
void init(void);
void game(sfRenderWindow *window);
void b_tower(sfRenderWindow *window);
void init_tw(void);
void game_pause(sfRenderWindow *window);
void init_tw2(void);
void print_tower(sfRenderWindow *window);
void user_p(sfRenderWindow *window);
void init_user2(void);
void init_user(void);
char *into_str(int nb);
void initz1(void);
void initz2(void);
void mv(void);
sfVector2f mv1(sfVector2f pos, float speed);
sfVector2f mv1_2(sfVector2f pos, float speed);
sfVector2f mv2(sfVector2f pos, float speed);
sfVector2f mv2_2 (sfVector2f pos, float speed);
int rand_inter(int i, int x);
void initz2(void);
void initz2b(int i);
void initz3(void);
void initz3b(void);
void en2(sfRenderWindow *window);
void init_atk(void);
void attack(sfRenderWindow *window);
void init_menu(void);
void menu3(sfRenderWindow *window, int i);
void cr_atkz2(int i);
void cr_atkz1(int i);
void cr_atk(sfRenderWindow *window);
void att_check(void);
void life_check(void);
void cr_atkt4(int i, sfRenderWindow *window);
void game_over(sfRenderWindow *window);
void init_htp2(void);
void init_htp(void);
void life_check2(void);
void init_over(void);
void init_over2(void);
void cr_atk43(int i);
void cr_atk42(int i, sfRenderWindow *window);
void game_over2(sfRenderWindow *window);
void game_over3(sfRenderWindow *window);
void game_pause2(sfVector2i pos);
void b_tower25(sfVector2i pos, int i);
void init_sound(void);
void init_zomb3(void);
void en3(sfRenderWindow *window);
void en3(sfRenderWindow *window);
void cr_atkz3(int i);
void init_zomb3b(void);
float order2(int i, float tmp);
void atkzo3(int i, int e, sfRenderWindow *window);
void atkzo3k(int i, int e);
void life_check3(void);
void cr_atk4z3(int i, sfRenderWindow *window);
#endif /* !MY_H_ */