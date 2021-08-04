#include <iostream>
#include "fb.h"
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int ch;
    manager m;
    player_splay st;
    splayer *root;
    root = NULL;

    float r, money;
    int pid, i;

    vector<player> p1{{"G1", "GK", 1, 1, 3, 3, 4, 1}, {"L1", "LB", 2, 3, 2, 2.3, 6, 1}, {"C1", "CB", 4, 1, 2, 1.6, 10, 1}, {"R1", "RB", 4, 2, 3.1, 2.7, 4, 1}, {"L2", "LM", 5, 6, 2.5, 1.3, 9, 1}, {"M2", "CM", 6, 8, 3.1, 1.6, 14, 1}, {"R2", "RM", 7, 10, 1.8, 2.9, 9, 1}, {"L3", "LW", 8, 7, 2.8, 2.1, 1, 1}, {"C3", "CF", 9, 9, 3.2, 1.2, 3, 1}, {"R3", "RW", 10, 11, 2.1, 2.2, 5, 1}};
    vector<player> p2{{"G1", "GK", 1, 1, 5, 5, 4, 1}, {"L1", "LB", 2, 3, 2.1, 5.3, 6, 1}, {"C1", "CB", 4, 1, 3.1, 5.7, 10, 1}, {"R1", "RB", 4, 2, 4.5, 5.5, 4, 1}, {"L2", "LM", 5, 6, 4.5, 5.3, 9, 1}, {"M2", "CM", 6, 8, 5.2, 4.5, 14, 1}, {"R2", "RM", 7, 10, 5.7, 5.5, 9, 1}, {"L3", "LW", 8, 7, 6.3, 3.1, 1, 1}, {"C3", "CF", 9, 9, 5.9, 2.8, 3, 1}, {"R3", "RW", 10, 11, 6.2, 1.5, 5, 1}};
    vector<player> p3{{"G1", "GK", 1, 1, 7, 7, 4, 1}, {"L1", "LB", 2, 3, 3.4, 6.1, 6, 1}, {"C1", "CB", 4, 1, 2, 7.1, 10, 1}, {"R1", "RB", 4, 2, 3.5, 6.8, 4, 1}, {"L2", "LM", 5, 6, 6.5, 6.5, 9, 1}, {"M2", "CM", 6, 8, 8.2, 7.3, 14, 1}, {"R2", "RM", 7, 10, 7.4, 7.9, 9, 1}, {"L3", "LW", 8, 7, 9.1, 4.2, 1, 1}, {"C3", "CF", 9, 9, 8.6, 4.3, 3, 1}, {"R3", "RW", 10, 11, 7.8, 2.9, 5, 1}};

    team t1{1, 1, "SuperChalengers", p1};
    team t2{1, 1, "SoccerKings", p2};
    team t3{1, 1, "PhantomWarriors", p3};

    vector<player> mp{{"Oblak", "GK", 1, 1, 4, 4, 4, 0}, {"Mendy", "GK", 2, 1, 6.1, 5, 6, 0}, {"Lloris", "GK", 3, 1, 6.3, 7.2, 10, 0}, {"Marcelo", "LB", 4, 3, 5.1, 7.5, 8, 0}, {"Ragul", "LB", 5, 3, 7.5, 7.9, 11, 0}, {"Dhoni", "LB", 6, 3, 5.5, 8.3, 14, 0}, {"Sachin", "CB", 7, 4, 5.8, 7.5, 9, 0}, {"Ramos", "CB", 8, 4, 6.9, 9.5, 19, 0}, {"Dravid", "CB", 9, 4, 5.6, 8.5, 9, 0}, {"Rohit", "RB", 10, 2, 4, 6, 5, 0}, {"Kohli", "RB", 11, 2, 4.7, 7, 7, 0}, {"Virat", "RB", 12, 2, 4, 5, 4, 0}, {"Sharma", "LM", 13, 6, 4.4, 7, 9, 0}, {"Raina", "LM", 14, 6, 7.5, 8, 6, 0}, {"Bumrah", "LM", 15, 6, 4, 9, 11, 0}, {"Smith", "CM", 16, 8, 6, 9, 14, 0}, {"Jaddu", "CM", 17, 8, 5.3, 6.3, 8, 0}, {"ABD", "CM", 18, 8, 8, 6.9, 11, 0}, {"Neymar", "RM", 19, 10, 9.3, 7, 8, 0}, {"Pandya", "RM", 20, 10, 5.3, 6, 7, 0}, {"Sam", "RM", 21, 10, 4.4, 8.3, 10, 0}, {"Ronaldo", "LW", 22, 7, 7.2, 9.5, 20, 0}, {"Dhileep", "LW", 23, 7, 8.1, 9.2, 18, 0}, {"Griez", "LW", 24, 7, 8.8, 7, 11, 0}, {"Prateek", "CF", 25, 9, 7.7, 9.2, 16, 0}, {"Kumar", "CF", 26, 9, 7.5, 8.1, 13, 0}, {"Sriram", "LW", 27, 7, 4.5, 6.5, 9, 0}, {"Messi", "RW", 28, 11, 10, 6.8, 20, 0}, {"Ashok", "RW", 29, 11, 7.5, 9.5, 19, 0}, {"Guru", "RW", 30, 11, 5.5, 6.5, 9, 0}};

    for (i = 0; i < mp.size(); i++)
    {
        root = st.Insert(mp[i].total_rating, root);
    }

    system("clear");
    cout << "\nWelcome to Football Manager Game";
    cout << "\n\nEnter Your Name: ";
    getline(cin, m.manager_name);
    cout << "\nEnter Club Name: ";
    getline(cin, m.mt.team_name);
    system("clear");
    cout << "\n\nOwner: Welcome " << m.manager_name << ", you are appointed as the new manager for the " << m.mt.team_name << " Club.";
    cout << "\nOwner: Create a team of 10 and bring us the Football Championship Trophy this Season.";
    cout << "\nOwner: I believe in you, " << m.manager_name;
    cout<<"\nPress Enter to continue..";
    cin.get();
    do
    {
        system("clear");
        cout << "\n\n-------------------------------------------------- MANAGER MENU ----------------------------------------------------------------";
        cout << "\n\n1.Manage Team\n2.Football Championship\n3.Player Market\n4.Rules\n5.Quit" << endl;
        cin >> ch;
        check_team(m.mt.p);
        switch (ch)
        {
        case 1:
        {
            
            do
            {
                system("clear");
                cout << "\n\n-------------------------------------------------  MANAGE TEAM   -------------------------------------------------------------";
                cout << "\n\n1.Team\n2.Change Players\n3.Back" << endl;
                cin >> ch;
                switch (ch)
                {
                case 1:
                {
                    cout << "\n\n-----------------------------------------------------   TEAM   -------------------------------------------------------------";
                    if (!m.mt.p.empty())
                    {
                        cout << "\n\nP_ID\tName\t\tPosition  Position Number\tOffense Rating\tDefense Rating\tTotal Rating\t Value (Millions)\tPlaying X\n";
                        for (i = 0; i < m.mt.p.size(); i++)
                        {
                            m.mt.p[i].show_player();
                            m.mt.p[i].display_playing();
                        }

                        cout<<"\nPress Enter to continue..";
                        cin.get();
                        cin.get();
                    }
                    else
                    {
                        cout << "\n\nNo Players Available!! Buy players from player Market.";
                        cout<<"\nPress Enter to continue..";
                        cin.get();
                        cin.get();
                    }

                    break;
                }

                case 2:
                {
                    cout << "\n\n----------------------------------------------   PLAYER LIST   ------------------------------------------------------";
                    if (!m.mt.p.empty())
                    {
                        cout << "\n\nP_ID\tName\t\tPosition  Position Number\tOffense Rating\tDefense Rating\tTotal Rating\t Value (Millions)\tPlaying X\n";
                        for (i = 0; i < m.mt.p.size(); i++)
                        {
                            m.mt.p[i].show_player();
                            m.mt.p[i].display_playing();
                        }

                        cout << "\n\nEnter Player ID to include in team: ";
                        cin >> pid;
                        if(return_index(m.mt.p,pid)==-1)
                        {
                            cout<<"\n\nIncorrect Player Id";
                        }
                        else
                        {
                        swap_players(m.mt.p, pid);
                        }
                        cout<<"\nPress Enter to continue..";
                        cin.get();
                        cin.get();
                    }
                    else
                    {
                        cout << "\n\nNo Players Available!! Buy players from player Market.";
                        cout<<"\nPress Enter to continue..";
                        cin.get();
                        cin.get();
                    }
                    break;
                }

                case 3:
                {
                    break;
                }

                case 4:
                {
                    exit(0);
                }

                default:
                {
                    cout << "\nIncorrect Option";
                    cout<<"\nEnter to continue..";
                    cin.get();
                    cin.get();
                    
                }
                }
            } while (ch != 3);

            break;
        }

        case 2:
        {
            do
            {
                system("clear");
                
                if(m.mt.level==4 && if_championship_winner(m.mt,t1,t2,t3)==true )
                {
                    cout<<"\n\nOwner : Congratulations "<<m.manager_name<<", you have won the Football Championship Trophy!!";
                    cout<<"\nOwner : You deserve all the credit\nManager : You have made me and your nation proud!";
                    cout<<"\nOwner : All the best for your future endeavours";

                    cout<<"\n\nPress enter to continue..";
                    cin.get();
                    cin.get();
                    m.mt.level++;
                }
                if(m.mt.level==4 && if_championship_winner(m.mt,t1,t2,t3)==false )
                {
                    cout<<"\nOwner : You lost the precious Football Championship Trophy";
                    cout<<"\nOwner : I had so much faith in you";
                    cout<<"\nOwner : You are Fired!! Try harder next season for a different club"; 

                    cout<<"\n\nPress enter to continue..";
                    cin.get();
                    m.mt.level++;
                }

                cout << "\n\n-------------------------------------------   FOOTBALL CHAMPIONSHIP  -----------------------------------------------------";
                cout << "\n\n1.Fixtures\n2.Play Match\n3.Table \n4.Back" << endl;
                cin >> ch;

                

                switch (ch)
                {
                case 2:
                {
                    if (check_key_players(m.mt.p))
                    {
                        if (m.mt.level == 1)
                        {
                            cout<<"\n\n Day "<<m.mt.level;
                            match(1, m, t1);
                            simulate_matches(2,t2, t3);
                        }
                        else if (m.mt.level == 2)
                        {
                            match(3, m, t2);
                            simulate_matches(4,t1, t3);
                        }
                        else if (m.mt.level == 3)
                        {
                            simulate_matches(5,t1, t2);
                            match(6, m, t3);
                        }
                        else
                        {
                            cout << "\n\nChampionship matches have ended !";
                            cout<<"\nEnter to continue..";
                            cin.get();
                            cin.get();
                        }
                    }
                    else
                    {
                        cout << "\n\nNot Enough Key Players, buy players from player market";
                        cout<<"\nEnter to continue..";
                        cin.get();
                        cin.get();
                    }
                    break;
                }

                case 1:
                {
                    if (m.mt.level == 4)
                    {
                        cout << "\n\n";
                        cout << "\n\nThis season's Championship matches have ended !";
                        cout<<"\nEnter to continue..";
                        cin.get();
                        cin.get();
                    }

                    cout << "\n\n--------------------------------------------------  FIXTURES  -------------------------------------------------------";
                    cout << "\n\nDay 1";
                    cout << "\n1.\t" << m.mt.team_name << " VS \t" << t1.team_name;
                    cout << "\n2.\t" << t2.team_name << " VS \t" << t3.team_name;
                    cout << "\n\nDay 2";
                    cout << "\n3.\t" << t2.team_name << " VS \t" << m.mt.team_name;
                    cout << "\n4.\t" << t1.team_name << " VS \t" << t3.team_name;
                    cout << "\n\nDay 3";
                    cout << "\n5.\t" << t1.team_name << " VS \t" << t2.team_name;
                    cout << "\n6.\t" << m.mt.team_name << " VS \t" << t3.team_name;
                    
                    cout<<"\n\nEnter to continue..";
                    cin.get();
                    cin.get();

                    break;
                }

                case 3:
                {
                    if (m.mt.level == 4)
                    {
                        cout << "\n\n";
                        championship_winners(m.mt, t1, t2, t3);
                    }

                    cout << "\n\n------------------------------------------  Football Championship Table  -------------------------------------------------------------";
                    cout << "\n\nTeam Name\tMatchesPlayed\tWins\tLosses\tDraws\tPoints";
                    cout << "\n\n"
                         << m.mt.team_name << "\t\t" << m.mt.matches_played << "\t    " << m.mt.wins << "\t" << m.mt.lost << "\t" << m.mt.draws <<"\t"<< m.mt.calpoints();
                    cout << "\n"
                         << t1.team_name << "\t\t" << t1.matches_played << "\t    " << t1.wins << "\t" << t1.lost << "\t" << t1.draws <<"\t"<< t1.calpoints();
                    cout << "\n"
                         << t2.team_name << "\t\t" << t2.matches_played << "\t    " << t2.wins << "\t" << t2.lost << "\t" << t2.draws <<"\t"<< t2.calpoints();
                    cout << "\n"
                         << t3.team_name << "\t\t" << t3.matches_played << "\t    " << t3.wins << "\t" << t3.lost << "\t" << t3.draws <<"\t"<< t3.calpoints();

                    
                    cout<<"\n\nEnter to continue..";
                    cin.get();
                    cin.get();

                    break;
                }

                case 4:
                {
                    break;
                }

                default:
                {
                    cout << "\nIncorrect Option";
                    cout<<"\nEnter to continue..";
                    cin.get();
                    cin.get();
                }
                }
            } while (ch != 4);

            break;
        }

        case 3:
        {
            do
            {
                system("clear");
                cout << "\n\n------------------------------------------------  PLAYER MARKET   -----------------------------------------------------";
                money = m.return_budget();
                cout << "\n\nBudget : " << money << " Million";
                cout << "\n\n1.Buy Player\n2.Sell Player\n3.Back\n"<< endl;
                cin >> ch;

                switch (ch)
                {
                case 1:
                {
                    do
                    {
                        cin.get();
                        cout << "\n\nBudget : " << money << " Million";
                        cout << "\n\n----------------------------------------------   PLAYER LIST   ------------------------------------------------------";
                        cout << "\n\nP_ID\tName\t\tPosition  Position Number\tOffense Rating\tDefense Rating\tTotal Rating\t Value (Million)\n";
                        st.inorder(root, mp);
                        cout << "\n\nEnter Player to buy : ";
                        cin >> pid;

                        if (return_index(mp, pid) == -1)
                        {
                            cout << "\n\nIncorrent Player ID";
                        }
                        else
                        {
                            pid = return_index(mp, pid);
                            if (m.budget_check(mp[pid].return_value()))
                            {
                                money = m.update_budget_buy(mp[pid].return_value());
                                cout << "\n\nP_ID\tName\t\tPosition  Position Number\tOffense Rating\tDefense Rating\tTotal Rating\t Value (Million)\n";
                                mp[pid].show_player();
                                m.mt.p.insert(m.mt.p.begin(), mp[pid]);
                                cout << "\n\nRemaining Budget : " << money << " Million";
                                mp.erase(mp.begin() + pid);
                                root = st.Delete(r, root);

                                cout << "\n\n---------------------------------------------  TEAM PLAYER LIST   ---------------------------------------------";
                                cout << "\n\nP_ID\tName\t\tPosition  Position Number\tOffense Rating\tDefense Rating\tTotal Rating\t Value (Millions)\n";
                                for (i = 0; i < m.mt.p.size(); i++)
                                {
                                    m.mt.p[i].show_player();
                                }
                            }
                            else
                            {
                                cout << "\n\nNot enough budget to buy this player!!";
                                cout<<"\nPress Enter to continue..";
                                cin.get();
                                cin.get();
                            }
                        }
                        cout << "\n\nBuy more player? (0/1)";
                        cin >> ch;
                    } while (ch);

                    break;
                }

                case 2:
                {
                    cout << "\n\n--------------------------------------------  TEAM PLAYER LIST   -------------------------------------------------------";
                    if (!m.mt.p.empty())
                    {
                        cout << "\n\nP_ID\tName\t\tPosition  Position Number\tOffense Rating\tDefense Rating\tTotal Rating\t Value (Millions)\n";
                        for (i = 0; i < m.mt.p.size(); i++)
                        {
                            m.mt.p[i].show_player();
                        }

                        cout << "\n\nEnter Player Id to sell : ";
                        cin >> pid;
                        if (return_index(m.mt.p, pid) == -1)
                        {
                            cout << "\n\nIncorrent Player Id";
                            cout<<"\nPress Enter to continue..";
                            cin.get();
                            cin.get();
                        }
                        else
                        {
                            pid = return_index(m.mt.p, pid);
                            cout << "\n\nP_ID\tName\t\tPosition  Position Number\tOffense Rating\tDefense Rating\tTotal Rating\t Value (Millions)\n";
                            m.mt.p[pid].show_player();
                            cout << "\nAre you sure you want to sell above player?(1/0) : ";
                            cin >> ch;
                            if (ch == 0)
                            {
                                break;
                            }
                            else
                            {
                                mp.insert(mp.begin() + pid, m.mt.p[pid]);
                                root = st.Insert(mp[pid].total_rating, root);
                                money = m.update_budget_sell(m.mt.p[pid].return_value());
                                m.mt.p.erase(m.mt.p.begin() + (pid));

                                cout << "\nPlayer Sold Successfully";
                                cout << "\n\nRemaining Budget : " << money << " Million";
                                cout<<"\nPress Enter to continue..";
                                cin.get();
                                cin.get();
                            }
                        }
                    }
                    else
                    {
                        cout << "\n\nNo Players Available!! Buy players from player Market.";
                        cout<<"\nPress Enter to continue..";
                        cin.get();
                        cin.get();
                        
                    }
                    break;
                }

                case 3:
                {
                    break;
                }

                default:
                {
                    cout << "\nIncorrect Option";
                    cout<<"\nPress Enter to continue..";
                    cin.get();
                    cin.get();
                }
                }
            } while (ch != 3);

            break;
        }

        case 4:
        {
            cout << "\n\n---------------------------------------------  Rules   ---------------------------------------------------------";
            cout << "\n\nThis is Football Manager Game";
            cout << "\nIt is managerial game where you will be asked to create and manage your own club.";
            cout << "\n1. You must have players from all ten positions to start a match\n2.Your purchase cost must not exceed the initial budget given to you.";
            cout<<  "\n3. There are 4 types of players:	\n\ta) Goal Keeper GK \n\tb) Defender LB,CB,RB(Left-Back, Centre Back, Right-Back)\n\tc) Midfield LM,CM,RM(Left-Mid, Centre Mid, Right-Mid) \n\td) Attacker LW,CF,RW(Left-Wing, Centre Forward, Right-Wing)";
            cout<< "\n4. You can buy and sell players at the player market";
            cout<< "\n5 ALL POSITION PLAYERS ARE NEEDED IN A TEAM TO START A MATCH";
            cout<< "\n6. You can only pass according to the hierarchy. (Goal keeper to defense, defense to midfield, midfield to attacker)";
            cout<< "\n7. Players can only intercept other players at Midfield and Defensive positions.";
            cout<< "\n8 Intercepts are made by comparing player offensive and defensive rating at overlapping position.";
            cout<< "\n9. First team to score wins, NO SECOND CHANCES";
            cout<< "\n10. Total 4 attempts are allowed, both teams included. If no team score after 4th attempt, match is draw.";
            cout<< "\n11. Total 3 matches are played by each team in the Championship";
            cout<< "\n12. Three points for a win, one point for a draw and zero points for loss";
            cout<< "\n13. The team with maximum points is awarded the Football Championship Trophy";
            cout<< "\n\nMAY THE TEAM WITH BEST TEAM WIN" ;
            cout<<"\n\nPress Enter to continue..";
            cin.get();
            cin.get();
            break;
        }

        case 5:
        {
            system("clear");
            exit(0);
            break;
        }

        default:
        {
            cout << "\nIncorrect Option";
            cout<<"\nPress Enter to continue..";
            cin.get();
            cin.get();
        }

        }
    } while (ch != 5);

    return 0;
}
