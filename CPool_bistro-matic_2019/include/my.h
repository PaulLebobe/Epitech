/*
** EPITECH PROJECT, 2019
** include
** File description:
** prototype
*/

#define ABS(x) ((x) < (0) ? (-x) : (x))

#define T(x, y) ((x) > (y) ? (x) : (y))

#define SYNTAX "syntax error"

#define ERROR "error"

char *removezero(char *str);

char *checkminus(char *str);

char *removespace(char *str);

char *rmdoubleneg(char *str);

char **my_malloc2(int i);

char *check_zero(char *str);

char *my_malloc(int i);

char *lastneg(char *str);

char *changeop(char *str, char *operator);

int my_power_int(int nb, int p);

char *getdiv(char *temp, char *str2);

char *dectobase(char *nbr, char const *base);

char getcharbase(char *str, char const *base);

char *my_power(char *nb, char *p);

char *getdecimalnbr(char *nbr, char const *base);

int getcharvalue(char nbr, char const *base);

char *basetodecimal(char *str, char const *base);

char *aff_res(char *prem, char *sec);

char *rmdoubleneg(char *str);

char *factinf(char *pr, char *sec);

char *getcharfact(char *prem, char sec, int *keepnbr, int y);

char *removespace(char *str);

char *into_str(int nb);

void fillres(int *i, int *e, char *result, int *nb);

int is_bigger(char *str, char *str2);

char *mod(char *str, char *str2);

char *divis(char *str, char *str2);

char *sub(char *str, char *str2, int neg);

void loop2(char *str, int *i, char nb, char *result);

char *inffact(char *fact, char *mult);

int my_strlen(char const *);

int my_putstr(char *str);

char *two_neg(char *, char *);

char *one_neg(char *, char *);

int my_strcmp (char *s1, char *s2);

char *two_positiv(char *pr, char *sec);

int isop(char c);

char *sum(char *str);

int my_putchar(char c);

int my_put_nbr(int nb);

int my_getnbr(char const *str);

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

char *my_revstr(char *str);

char *into_str(int nb);

char leftnbr(char *str, char *nb, int *e, int *i);

void rightnbr(char *str, char *nb2, int *i);

char *add_sub(char *);

char *calcul(char *str, char *str2, char sign);

char *rmparenthese(char *str);

char *priority(char *str);

char *facto(char *str);

int isop(char c);

char *checkminus(char *str);

char *eval_expr(char *str, char *base, char *op);

int error(char **av);
