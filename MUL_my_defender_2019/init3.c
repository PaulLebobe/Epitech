/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init3
*/

#include "my.h"

void init_sound(void)
{
    for (int i = 0; i < 2; i++)
        over.sound[i] = sfSound_create();
    over.buff[0] = sfSoundBuffer_createFromFile("sounds/epic.ogg");
    sfSound_setBuffer(over.sound[0], over.buff[0]);
    over.buff[1] = sfSoundBuffer_createFromFile("sounds/wilhelm.ogg");
    sfSound_setBuffer(over.sound[1], over.buff[1]);
    sfSound_play(over.sound[0]);
    sfSound_setLoop(over.sound[0], sfTrue);
}

void init_htp2(void)
{
    sfText_setString(htp.text[0], "How to play");
    sfText_setString(htp.text[1], "Hi, stranger our kingdom is invaded b\
y zombies (coming from your right)");
    sfText_setString(htp.text[2], "Fortunately there are 12 locations where \
you have to buy towers using your mouse");
    sfText_setString(htp.text[3], "The archer tower hits the most quickly");
    sfText_setString(htp.text[4], "The arcane tower has more range and power");
    sfText_setString(htp.text[5], "The poison tower deals over time damages");
    sfText_setString(htp.text[6], "The storm tower makes area damages");
    sfText_setString(htp.text[7], "Zombies scare us, your towers will focus th\
e zombie the most ahead in their range");
    sfText_setString(htp.text[8], "Playing you can pres\
s escape to take a breath");
    sfText_setString(htp.text[9], "Press space to go back");
}

void init_htp(void)
{
    htp.font = sfFont_createFromFile("contrast.ttf");
    htp.temp = 0;
    htp.scale = 0;
    for (int i = 1; i < 10; i++) {
        htp.text[i] = sfText_create();
        sfText_setFont(htp.text[i], htp.font);
        sfText_setFillColor(htp.text[i], (sfColor) {255, 255, 255, 255});
        sfText_setPosition(htp.text[i], (sfVector2f) {50, 100 + i * 75});
    }
    htp.text[0] = sfText_create();
    sfText_setFont(htp.text[0], htp.font);
    sfText_setFillColor(htp.text[0], (sfColor) {255, 255, 255, 255});
    sfText_setPosition(htp.text[0], (sfVector2f) {50, 50});
    init_htp2();
    init_over();
}

void init_atk(void)
{
    ia[0].text[0] = sfTexture_createFromFile
    ("tw_folder/a_archer.png", NULL);
    ia[0].text[1] = sfTexture_createFromFile
    ("tw_folder/a_arcane.png", NULL);
    ia[0].text[2] = sfTexture_createFromFile
    ("tw_folder/a_poison.png", NULL);
    ia[0].text[3] = sfTexture_createFromFile
    ("tw_folder/a_elec.png", NULL);
    for (int i = 0; i < 12; i++) {
        ia[i].sprite = sfSprite_create();
        ia[i].cl = sfClock_create();
        for (int e = 0; e < 50; e++) {
            ia[i].pos[e] = (sfVector2f) {5000, 5000};
        }
    }
    init_htp();
}