#ifndef FB_H
#define FB_H
#include <iostream>
#include <vector> 

using namespace std;
struct player
{
    string name, postion;
    int id, position_number;
    float offense_rating, defense_rating,total_rating,value;
    int playing;
    player(string n,string pos,int id,int pno,float orat,float dr,float value,int playing);
    void show_player();
    void display_playing();
    float return_value();
    int return_pid();
    int return_player_position_no();
    void assign_to_team();
    float return_or();
    float return_dr();
};

struct team
{
    int teamno, level, matches_played, wins, lost, draws;
    string team_name;
    vector<player> p{};  

    team();
    team(int,int,string,vector<player>);
    float return_player_offense_rating(int pno);
    float return_player_defense_rating(int pno);
    void display_player_offense_rating(int pno);
    void display_player_defense_rating(int pno);
    void return_player_name(int pno);
    int calpoints();
};

struct manager
{
    team mt;
    string manager_name;
    float money;

    manager();
    float return_budget();
    float update_budget_buy(float);
    float update_budget_sell(float);
    bool budget_check(float);

};

struct splayer
{
    float rating;
    splayer *left;
    splayer *right;
};

class player_splay
{
public:

    player_splay();
    splayer *RR_Rotate(splayer *k2);
    splayer *LL_Rotate(splayer *k2);
    splayer *Splay(float rating, splayer *root);
    splayer *New_Node(float rating);
    splayer *Insert(float rating, splayer *root);
    splayer *Delete(float rating, splayer *root);
    void inorder(splayer *root,vector<player> p);
};

float return_total_rating_pid(int pid,vector<player> p);
void return_player(float rating,vector<player> p);
void add_players_to_field();
int toss(int coin);
void match(int mno, manager &m, team &t);
int return_index(vector<player>p,int pid);
void check_team(vector<player> &p);
bool check_key_players(vector<player> p);
void swap_players(vector<player> &p,int pid);
bool if_player_already(vector<player> p,int pno);

void pass(int,int,manager& m,team &t2);
void return_position_name(int);
bool intercept(int from,int to);
int return_posno_verticeno(int);
int goal_chance(team t);
void simulate_matches(int,team &t1, team&t2);
void championship_winners(team t1,team t2,team t3,team t4);
bool if_championship_winner(team,team,team,team);

#endif