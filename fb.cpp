#include <iostream>
#include "fb.h"
#include <cstdlib>
#include <vector>
#include <math.h>

using namespace std;
vector<int> playground[20];
int m_won = -1;
int draw_count = 0;

player::player(string n, string pos, int id, int pno, float orat, float dr, float value, int playing)
{
    this->name = n;
    this->postion = pos;
    this->id = id;
    this->position_number = pno;
    this->offense_rating = orat;
    this->defense_rating = dr;
    this->value = value;
    this->playing = 0;
    this->total_rating = (this->offense_rating + this->defense_rating) / 2;
}

void player::show_player()
{
    cout << "\n"<< this->id;
    cout << "\t" << this->name;
    cout << "\t\t  " << this->postion;
    cout << "\t\t" << this->position_number;
    cout << "\t\t\t" << this->offense_rating;
    cout << "\t\t" << this->defense_rating;
    cout << "\t\t" << this->total_rating;
    cout << "\t\t" << this->value;
}

void player::display_playing()
{
    if (this->playing == 1)
    {
        cout << "\t\t  Yes" << endl;
    }
    else
    {
        cout << "\t\t  No" << endl;
    }
}

float player::return_value()
{
    return value;
}

int player::return_pid()
{
    return this->id;
}

int player::return_player_position_no()
{
    return this->position_number;
}

void player::assign_to_team()
{
    this->playing = 1;
}


team::team(int tno, int lv, string tname, vector<player> players)
{
    this->teamno = tno;
    this->level = lv;
    this->matches_played = 0;
    this->wins = 0;
    this->lost = 0;
    this->draws = 0;
    this->team_name = tname;
    this->p = players;
}

team::team()
{
    this->matches_played = 0;
    this->level = 1;
    this->wins = 0;
    this->lost = 0;
    this->draws = 0;
}

int team::calpoints()
{

    return ((3 * this->wins) + (1 * this->draws) + (0 * this->lost));
}

float player::return_or()
{
    return this->offense_rating;
}

float player::return_dr()
{
    return this->defense_rating;
}

void return_player(float rating, vector<player> p)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (rating == p[i].total_rating)
        {
            p[i].show_player();
        }
    }
}

float return_total_rating_pid(int pid, vector<player> p)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (pid == p[i].id)
        {
            return p[i].total_rating;
        }
    }
    return -1;
}

int return_index(vector<player> p, int pid)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (pid == p[i].return_pid())
            return i;
    }

    return -1;
}

bool if_player_already(vector<player> p, int pno)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].return_player_position_no() == pno && p[i].playing == 1)
        {
            return true;
            break;
        }
    }
    return false;
}

 void championship_winners(team t1,team t2,team t3,team t4)
 {
    for(int i=9;i>=0;i--)
    {
        if(i=t1.calpoints())
        {
            cout<<"\n\n\n Congratulations "<<t1.team_name<<" are this season's Football Championship winners";
            break;
        }
        else if(i=t2.calpoints())
        {
            cout<<"\n\n\n Congratulations "<<t2.team_name<<" are this season's Football Championship winners";
            break;
        }
        else if(i=t3.calpoints())
        {
            cout<<"\n\n\n Congratulations "<<t3.team_name<<" are this season's Football Championship winners";
            break;
        }
        else if(i=t4.calpoints())
        {
            cout<<"\n\n\n Congratulations "<<t4.team_name<<" are this season's Football Championship winners";
            break;
        }
    }
 }
 bool if_championship_winner(team t1,team t2,team t3,team t4)
 {
     for(int i=9;i>=0;i--)
    {
        if(i=t1.calpoints())
        {
            return true;
        }
        else if(i=t2.calpoints())
        {
            return false;
        }
        else if(i=t3.calpoints())
        {
            return false;
        }
        else if(i=t4.calpoints())
        {
            return false;
        }
    }
    return false;
 }

void check_team(vector<player> &p)
{
    vector<int> pno{1, 3, 4, 2, 6, 8, 10, 7, 9, 11};
    int i, j;
    for (i = 0; i < pno.size(); i++)
    {
        for (j = 0; j < p.size(); j++)
        {
            if (if_player_already(p, pno[i]))
            {
                break;
            }
            else if (p[j].return_player_position_no() == pno[i])
            {
                p[j].assign_to_team();
                break;
            }
        }
    }
}
bool check_key_players(vector<player> p)
{
    int c = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].playing == 1)
            c++;
    }
    if (c == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void swap_players(vector<player> &p, int pid)
{
    pid = return_index(p, pid);
    int pno = p[pid].return_player_position_no();
    if(p[pid].playing==1)
    {
        cout<<"\nPlayer already in team";
    }
    else
    {
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].position_number == pno && p[i].playing == 1)
        {
            p[i].playing = 0;
            break;
        }
    }
    p[pid].assign_to_team();
    cout << "\n\nPlayers Sucessfully Swapped";
    }
}

manager::manager() { money = 100; }

float manager::return_budget()
{
    return money;
}

float manager::update_budget_buy(float value)
{
    money = money - value;
    return money;
}
float manager::update_budget_sell(float value)
{
    money = money + value;
    return money;
}

bool manager::budget_check(float value)
{
    return money >= value;
}

float team::return_player_offense_rating(int pno)
{
    if (!this->p.empty())
    {
        for (int i = 0; i < this->p.size(); i++)
        {
            if (this->p[i].return_player_position_no() == pno)
            {
                return this->p[i].return_or();
                break;
            }
        }
    }
    return -1;
}

    float team::return_player_defense_rating(int pno)
    {
        if (!this->p.empty())
        {
            for (int i = 0; i < this->p.size(); i++)
            {
                if (this->p[i].return_player_position_no() == pno)
                {
                    return this->p[i].return_dr();
                    break;
                }
            }
        }
        return -1;
    }

    void team::display_player_offense_rating(int pno)
    {
        if (!this->p.empty())
        {
            for (int i = 0; i < this->p.size(); i++)
            {
                if (this->p[i].return_player_position_no() == pno)
                {
                    cout << this->p[i].return_or();
                    break;
                }
            }
        }
    }

    void team::return_player_name(int pno)
    {
        if (!this->p.empty())
        {
            for (int i = 0; i < this->p.size(); i++)
            {
                if (this->p[i].return_player_position_no() == pno)
                {
                    cout << this->p[i].name;
                    break;
                }
            }
        }
    }

    void team::display_player_defense_rating(int pno)
    {
        if (!this->p.empty())
        {
            for (int i = 0; i < this->p.size(); i++)
            {
                if (this->p[i].return_player_position_no() == pno)
                {
                    cout << this->p[i].return_dr();
                    break;
                }
            }
        }
    }


    void simulate_matches(int mno,team &t1, team&t2)
    {
        system("clear");
        cout<<"\n\n-------------------------------  OTHER MATCH RESULTS  ---------------------------------------------";
        cout << "\n\nMatch "<<mno<<"  "<<t1.team_name<<"   VS  "<<"\t"<<t2.team_name;
        int r;
        r=rand()%3;

         if (r==1)
        {
            t1.matches_played++;
            t1.lost++;
            t2.matches_played++;
            t2.wins++;    
            cout << "\n"<<t2.team_name<<" wins the match.";
        }
        else if (r==2)
        {
            t2.matches_played++;
            t2.lost++;
            t1.matches_played++;
            t1.wins++;
            cout << "\n"<<t1.team_name<<" wins the match.";
        }
        else
        {
            t1.matches_played++;
            t2.matches_played++;
            t1.draws++;
            t2.draws++;
            cout << "\nMatch declared draw";
        }

        cout<<"\n\nPress enter to continue..";
        cin.get();
    }



    void add_players_to_field()
    {
        int i = 0, j = 0;

        for (i = 0; i < 20; i++)
        {
            if (i == 0)
            {
                for (j = 1; j <= 3; j++)
                    playground[i].push_back(j);
            }
            else if (i == 1 || i == 2 || i == 3)
            {
                playground[i].push_back(i + 3);
                for (j = 7; j <= 9; j++)
                {
                    playground[i].push_back(j);
                }
            }
            else if (i == 7 || i == 8 || i == 9)
            {
                playground[i].push_back(i + 3);
                for (j = 13; j <= 15; j++)
                {
                    playground[i].push_back(j);
                }
            }
            else if (i == 13 || i == 14 || i == 15)
            {
                playground[i].push_back(19);
                playground[i].push_back(i + 3);
            }
            else if (i == 19)
            {
                for (j = 16; j <= 18; j++)
                    playground[i].push_back(j);
            }
            else if (i == 16 || i == 17 || i == 18)
            {
                playground[i].push_back(i - 3);
                for (j = 10; j <= 12; j++)
                {
                    playground[i].push_back(j);
                }
            }
            else if (i == 10 || i == 11 || i == 12)
            {
                playground[i].push_back(i - 3);
                for (j = 4; j <= 6; j++)
                {
                    playground[i].push_back(j);
                }
            }
            else if (i == 4 || i == 5 || i == 6)
            {
                playground[i].push_back(0);
                playground[i].push_back(i - 3);
            }
        }
    }

    int toss(int coin)
    {
        int rn;
        rn = rand() % 2;
        if ((int)rn == coin)
        {
            cout << "\n\nYou won the toss, you will kickoff";
            return 1;
        }
        else
        {
            cout << "\n\nYou lost the toss, opponent will kickoff";
            return 0;
        }
    }

    int return_posno_verticeno(int n)
    {
        if (n == 0 || n == 19)
        {
            return 1;
        }
        else if (n == 1 || n == 18)
        {
            return 3;
        }
        else if (n == 2 || n == 17)
        {
            return 4;
        }
        else if (n == 3 || n == 16)
        {
            return 2;
        }
        else if (n == 7 || n == 12)
        {
            return 6;
        }
        else if (n == 8 || n == 11)
        {
            return 8;
        }
        else if (n == 9 || n == 10)
        {
            return 10;
        }
        else if (n == 13 || n == 6)
        {
            return 7;
        }
        else if (n == 14 || n == 5)
        {
            return 9;
        }
        else if( n== 4 || n==15 )
        {
            return 11;
        }
        return -1;
    }

    bool intercept(int player, int opponent, team &t1, team &t2)
    {
        cout << "\n\t";
        return_position_name(return_posno_verticeno(player));
        cout << "(";
        t1.display_player_offense_rating(return_posno_verticeno(player));
        cout << ")"
             << "  VS  ";
        return_position_name(return_posno_verticeno(opponent));
        cout << "(";
        t2.display_player_offense_rating(return_posno_verticeno(opponent));
        cout << ")";

        if (t1.return_player_offense_rating(return_posno_verticeno(player)) >= t2.return_player_defense_rating(return_posno_verticeno(opponent)))
            return false;
        else
            return true;
    }

    void return_position_name(int n)
    {
        if (n == 1)
        {
            cout << "GK";
        }
        else if (n == 3)
        {
            cout << "LB";
        }
        else if (n == 4)
        {
            cout << "CB";
        }
        else if (n == 2)
        {
            cout << "RB";
        }
        else if (n == 6)
        {
            cout << "LM";
        }
        else if (n == 8)
        {
            cout << "CM";
        }
        else if (n == 10)
        {
            cout << "RM";
        }
        else if (n == 7)
        {
            cout << "LW";
        }
        else if (n == 9)
        {
            cout << "CF";
        }
        else if (n == 11)
        {
            cout << "RW";
        }
    
    }

    int goal_chance(team t)
    {
        int g,r;
        r=pow((t.return_player_defense_rating(return_posno_verticeno(1))),2);
        g =  1 + rand() % 100;

        if (g<=r)
        {
            return 0;
        }
        if (g>r && g <90)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    int ga=0;
    void pass(int from, int opp_goal, manager &m, team &t)
    {
        int to;

        if (from == opp_goal)
        {
            
            int g;
            g = goal_chance(t);
            ga++;
            if(ga==4)
            {
                m_won=5;
                return;
            }
            else
            {

            if (g == 2)
            {
                cout << "\nStriker completely missed the goal!!";
                cout<<"\nTotal Goal Attempt :"<<ga;

                if (from == 19)
                {
                    pass(19,0, m, t);
                }
                else
                {
                    pass(0, 19, m, t);
                }
            }
            else if (g == 0)
            {
                cout << "\nGoalkepeer saved the goal!!";
                cout<<"\nTotal Goal Attempt :"<<ga;

                if (from == 19)
                {
                    pass(19, 0, m, t);
                }
                else
                {
                    pass(0, 19, m, t);
                }
            }
            else
            {
                cout << "\nIt is a Goallllll !!!!";
                if (from== 19)
                {
                    m_won = 1;
                }
                else
                {
                    m_won = 0;
                }
                
                return;
            }
            }
        }
        else if (from == 0)
        {
            cout << "\n\nYour Goalkeeper has the ball";
            for (int i = 0; i < 3; i++)
            {
                cout << "\n"
                     << playground[from][i] << ". ";
                return_position_name(return_posno_verticeno(playground[from][i]));
                cout<<"\t";
                    m.mt.return_player_name(return_posno_verticeno(playground[from][i]));
            }
            cout << "\n\nSelect defender to pass :";
            cin >> to;
            pass(to, opp_goal, m, t);
        }
        else if (from == 19)
        {
            cout << "\n\nOpponent Goalkeeper has the ball";
            to = playground[from][0] + rand() % 3;
            cout << "\nOpponent passed the ball to his Defender: ";
            return_position_name(return_posno_verticeno(to));
            pass(to, opp_goal, m, t);
        }
        else if (from >= 1 && from <= 3)
        {
            cout << "\n\nYour Defender has the ball";
            for (int i = 1; i < 4; i++)
            {
                cout << "\n"
                     << playground[from][i] << ". ";
                return_position_name(return_posno_verticeno(playground[from][i]));
                cout<<"\t";
                    m.mt.return_player_name(return_posno_verticeno(playground[from][i]));
            }
            cout << "\n\nSelect Midfielder to pass :";
            cin >> to;
            pass(to, opp_goal, m, t);
        }
        else if (from >= 7 && from <= 9)
        {
            if (!intercept(from, playground[from][0], m.mt, t))
            {
                cout << "\nYour Midfielder has the ball\n";
                cout << "\nYour Midfielder has dribbled past the opponent!";
                for (int i = 1; i < 4; i++)
                {
                    cout << "\n"
                         << playground[from][i] << ". ";
                    return_position_name(return_posno_verticeno(playground[from][i]));
                    cout<<"\t";
                    m.mt.return_player_name(return_posno_verticeno(playground[from][i]));
                }
                cout << "\n\nSelect Striker to dribble and pass :";
                cin >> to;
                pass(to, opp_goal, m, t);
            }
            else
            {
                from = playground[from][0];
                cout << " \n\nOpponent Midfielder has intercepted the ball";
                to = playground[from][1] + rand() % 3;
                cout << "\nOpponent passed the ball to : "; 
                return_position_name(return_posno_verticeno(to));
                pass(to, 0, m, t);
            }
        }
        else if (from >= 13 && from <= 15)
        {
            if (!intercept(from, playground[from][1], m.mt, t))
            {
                cout << "\n\nYour Striker has the ball";
                cout << "\nYour Striker attemped a shot at goal:";
                pass(19, opp_goal, m, t);
            }
            else
            {
                from = playground[from][0];
                cout << " \n\nOpponent defender has intercepted the ball";
                to = playground[from+3][1] + rand() % 3;
                cout << "\nOpponent passed the ball to his striker: ";
                return_position_name(return_posno_verticeno(to));
                pass(to, 0, m, t);
            }
        }
        else if (from >= 16 && from <= 18)
        {
            cout << "\n\nOpponent defender has the ball. ";
            to = playground[from][1] + rand() % 3;
            cout << "\nOpponent passed the ball to his Midfielder: ";
            return_position_name(return_posno_verticeno(to));
            pass(to, opp_goal, m, t);
        }
        else if (from >= 10 && from <= 12)
        {
            if (!intercept(from, playground[from][0], t, m.mt))
            {
                cout << "\n\nOpponenet Midfielder has the ball";
                to = playground[from][1] + rand() % 3;
                cout << "\n\nOpponent has dribbled past your midfielder and passed the ball to Striker!";
                return_position_name(return_posno_verticeno(to));
                pass(to, opp_goal, m, t);
            }
            else
            {
                from = playground[from][0];
                cout << " \n\nYour midfielder intercepted the ball from opponent";
                for (int i = 1; i < 4; i++)
                {
                    cout << "\n"
                         << playground[from][i] << ". ";
                    return_position_name(return_posno_verticeno(playground[from][i]));
                    cout<<"\t";
                    m.mt.return_player_name(return_posno_verticeno(playground[from][i]));
                }
                cout << "\n\nSelect Striker to dribble and pass to:";
                cin >> to;
                pass(to, 19, m, t);
            }
        }

        else if (from >= 4 && from <= 6)
        {
            if (!intercept(from, playground[from][1], t, m.mt))
            {
                cout << "\nOpponent Striker has the ball";
                cout << "\nOpponent Striker attemped a shot at goal:";
                pass(0, opp_goal, m, t);
            }
            else
            {
                from = playground[from][0];
                cout << " \n\nYour defender intercepted the ball";
                for (int i = 1; i < 4; i++)
                {
                    cout << "\n"
                         << playground[from][i] << ". ";
                    return_position_name(return_posno_verticeno(playground[from][i]));
                    cout<<"\t";
                    m.mt.return_player_name(return_posno_verticeno(playground[from][i]));
                }
                cout << "\n\nSelect Midfielder to pass :";
                cin >> to;
                pass(to, 19, m, t);
            }
        }
    }

    void match(int mno, manager &m, team &t)
    {
        int coin;

        cout << "\n\n----------------  Match " << mno << ": " << m.mt.team_name << " VS " << t.team_name<<"   -------------------------------";

        add_players_to_field();

        cout << "\n\n-----------------------------------Goal Line--------------------------------------";
        cout << "\n\n\t\t\tGK (1)";
        cout << "\n\nRB (2)";
        cout << "\t\t\tCB (4)";
        cout << "\t\t\tLB (3)";

        cout << "\n\nRM (10)";
        cout << "\t\t\tCM (8)";
        cout << "\t\t\tLM (6)";

        cout << "\n\nRW (11)";
        cout << "\t\t\tCF (9)";
        cout << "\t\t\tLW (7)";

        cout << "\n\n---------------------------------Center Line--------------------------------------";

        cout << "\n\nLW (7,";
        m.mt.display_player_offense_rating(7);
        cout << ",";
        m.mt.display_player_defense_rating(7);
        cout << ")";

        cout << "\t\tCF (9,";
        m.mt.display_player_offense_rating(9);
        cout << ",";
        m.mt.display_player_defense_rating(9);
        cout << ")";

        cout << "\t\tRW (11,";
        m.mt.display_player_offense_rating(11);
        cout << ",";
        m.mt.display_player_defense_rating(11);
        cout << ")";

        cout << "\n\nLM (6,";
        m.mt.display_player_offense_rating(6);
        cout << ",";
        m.mt.display_player_defense_rating(6);
        cout << ")";

        cout << "\t\tCM (8,";
        m.mt.display_player_offense_rating(8);
        cout << ",";
        m.mt.display_player_defense_rating(8);
        cout << ")";

        cout << "\t\tRM (10,";
        m.mt.display_player_offense_rating(10);
        cout << ",";
        m.mt.display_player_defense_rating(10);
        cout << ")";

        cout << "\n\nLB (3,";
        m.mt.display_player_offense_rating(3);
        cout << ",";
        m.mt.display_player_defense_rating(3);
        cout << ")";

        cout << "\t\tCB (4,";
        m.mt.display_player_offense_rating(4);
        cout << ",";
        m.mt.display_player_defense_rating(4);
        cout << ")";

        cout << "\t\tRB (12,";
        m.mt.display_player_offense_rating(2);
        cout << ",";
        m.mt.display_player_defense_rating(2);
        cout << ")";

        cout << "\n\n\t\t\tGK (1,";
        m.mt.display_player_offense_rating(1);
        cout << ",";
        m.mt.display_player_defense_rating(1);
        cout << ")";
        cout << "\n\n---------------------------------Goal Line-----------------------------------------";

        cout << "\n\nLegend : Player(position_number, offensive_rating, defensive rating)";

        cout << "\nStart Match ? (press enter to continue)";
        cin.get();

        cout << "\n\nHeads(1) Or Tails(0) : ";
        cin >> coin;
        int pc;
        pc = toss(coin);

        ga=0;
        if (pc == 1)
        {
            pass(0, 19, m, t);
        }
        else
        {
            pass(19, 0, m, t);
        }

        if (m_won == 0)
        {
            m.mt.matches_played++;
            m.mt.lost++;
            t.matches_played++;
            t.wins++;
            m.mt.level++;
            m.money += 10;
            cout << "\n\nYou lost the match, Better luck next time";
            cout << "\n10 Million Credited.";
        }
        else if (m_won == 1)
        {
            t.matches_played++;
            t.lost++;
            m.mt.matches_played++;
            m.mt.wins++;
            m.mt.level++;
            m.money += 40;
            cout << "\n\nHurray!! You won the match, All the best for future";
            cout << "\n40 Million Credited.";
        }
        else
        {
            t.matches_played++;
            m.mt.matches_played++;
            t.draws++;
            m.mt.level++;
            m.mt.draws++;
            m.money += 10;
            cout<<"\n\nNeither Team scored a goal within 4 attempts";
            cout << "\nMatch declared draw, well fought!";
            cout << "\n\n10 Million Credited.";
        }

        cout<<"\n\nPress enter to continue..";
        cin.get();
        cin.get();
    }

    player_splay::player_splay() {}

    splayer *player_splay::RR_Rotate(splayer * k2)
    {
        splayer *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        return k1;
    }

    splayer *player_splay::LL_Rotate(splayer * k2)
    {
        splayer *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        return k1;
    }

    splayer *player_splay::Splay(float rating, splayer *root)
    {
        if (!root)
            return NULL;
        splayer header;
        header.left = header.right = NULL;
        splayer *LeftTreeMax = &header;
        splayer *RightTreeMin = &header;
        while (1)
        {
            if (rating < root->rating)
            {
                if (!root->left)
                    break;
                if (rating < root->left->rating)
                {
                    root = RR_Rotate(root);
                    if (!root->left)
                        break;
                }
                RightTreeMin->left = root;
                RightTreeMin = RightTreeMin->left;
                root = root->left;
                RightTreeMin->left = NULL;
            }
            else if (rating > root->rating)
            {
                if (!root->right)
                    break;
                if (rating > root->right->rating)
                {
                    root = LL_Rotate(root);
                    if (!root->right)
                        break;
                }
                LeftTreeMax->right = root;
                LeftTreeMax = LeftTreeMax->right;
                root = root->right;
                LeftTreeMax->right = NULL;
            }
            else
                break;
        }
        LeftTreeMax->right = root->left;
        RightTreeMin->left = root->right;
        root->left = header.right;
        root->right = header.left;
        return root;
    }

    splayer *player_splay::New_Node(float rating)
    {
        splayer *p_node = new splayer;
        if (!p_node)
        {
            fprintf(stderr, "Out of memory!\n");
            exit(1);
        }
        p_node->rating = rating;
        p_node->left = p_node->right = NULL;
        return p_node;
    }

    splayer *player_splay::Insert(float rating, splayer *root)
    {
        static splayer *p_node = NULL;
        if (!p_node)
            p_node = New_Node(rating);
        else
            p_node->rating = rating;
        if (!root)
        {
            root = p_node;
            p_node = NULL;
            return root;
        }
        root = Splay(rating, root);

        if (rating < root->rating)
        {
            p_node->left = root->left;
            p_node->right = root;
            root->left = NULL;
            root = p_node;
        }
        else if (rating > root->rating)
        {
            p_node->right = root->right;
            p_node->left = root;
            root->right = NULL;
            root = p_node;
        }
        else
            return root;
        p_node = NULL;
        return root;
    }

    splayer *player_splay::Delete(float rating, splayer *root)
    {
        splayer *temp;
        if (!root)
            return NULL;

        cout << "\nDeal done, player bought!!";
        root = Splay(rating, root);
        if (rating != root->rating)
            return root;
        else
        {
            if (!root->left)
            {
                temp = root;
                root = root->right;
            }
            else
            {
                temp = root;
                root = Splay(rating, root->left);
                root->right = temp->right;
            }
            free(temp);
            return root;
        }
    }

    void player_splay::inorder(splayer * root, vector<player> p)
    {
        if (root)
        {
            inorder(root->left, p);
            return_player(root->rating, p);
            inorder(root->right, p);
        }
    }