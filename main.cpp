#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <functional>
#include <map>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>

namespace WorkWithTickets
{

    struct Time
    {
        int minute;
        int hour;
    };

    struct Data
    {
        int day;
        int mounth;
        int year;
    };

    struct planeTicket
    {
        int flightNumber;
        std::string finalPoint;
        int numberDeparture;
        Time time;
        Data data;
        int cost;
        int sitNumber;
    };

    void init(planeTicket *a)
    {
        int fn, nD, c;
        std::string fP;
        Time time;
        Data data;
        std::cout << "Enter flight number: " << std::endl;
        std::cin >> fn;
        std::cout << "Enter final point: " << std::endl;
        std::cin >> fP;
        std::cout << "Enter number of departure: " << std::endl;
        std::cin >> nD;
        std::cout << "Enter hour and minut of flight: " << std::endl;
        std::cin >> time.hour >> time.minute;
        std::cout << "Enter data of the flight: " << std::endl;
        std::cin >> data.day >> data.mounth >> data.year;

        a->flightNumber = fn;
        a->finalPoint = fP;
        a->numberDeparture = nD;
        a->time.minute = time.minute;
        a->time.hour = time.hour;
        a->data.day = data.day;
        a->data.mounth = data.mounth;
        a->data.year = data.year;
    }

    void output(planeTicket a)
    {
        std::cout << "Flight number: " << std::endl;
        std::cout << a.flightNumber << std::endl;
        std::cout << "Final point: " << std::endl;
        std::cout << a.finalPoint << std::endl;
        std::cout << "Number of departure: " << std::endl;
        std::cout << a.numberDeparture << std::endl;
        std::cout << "Hour and minut of flight: " << std::endl;
        std::cout << a.time.hour << ' ' << a.time.minute;
        std::cout << "Data of the flight: " << std::endl;
        std::cout << a.data.day << ' ' << a.data.mounth << ' ' << a.data.year;
    }

    void del(planeTicket *a)
    {
        a->flightNumber = -1;
    }

    void clear(planeTicket *a)
    {
        a->cost = 0;
        a->finalPoint = "";
        a->flightNumber = 0;
        a->numberDeparture = 0;
        a->sitNumber = 0;
        a->data.day = 0;
        a->data.mounth = 0;
        a->data.year = 0;
        a->time.minute = 0;
        a->time.hour = 0;
    }

    void set(planeTicket *a, std::string typeOfChange, auto val)
    {
        std::cin >> val;
        switch (typeOfChange)
        {
        case "cost":
            a->cost = val;
        case "final point":
            a->finalPoint = val;
        case "flight number":
            a->flightNumber = val;
        case "number of departure":
            a->numberDeparture = val;
        case "sit number":
            a->sitNumber = val;
        case "day":
            a->data.day = val;
        case "mounth":
            a->data.mounth = val;
        case "year":
            a->data.year = val;
        default:
            break;
        };
    }

    struct elem
    {
        planeTicket val;
        elem *next;
        elem(planeTicket value) : val(value), next(nullptr) {}
    };

    struct list
    {
        elem *first;
        elem *last;

        list() : first(nullptr), last(nullptr) {}

        bool is_empty()
        {
            return first == nullptr;
        }

        void push_back(planeTicket val)
        {
            elem *p = new elem(val);
            if (is_empty())
            {
                first = p;
                last = p;
                return;
            }
            last->next = p;
            last = p;
        }

        void insertAtTheBegin(elem **start_ref, planeTicket d)
        {
            elem *ptr1 = (elem *)malloc(sizeof(elem));
            ptr1->val = d;
            ptr1->next = *start_ref;
            *start_ref = ptr1;
        }

        int findEmpty()
        {
            elem *p = first;
            int emptyInd = 0;
            while (p)
            {
                if (p->val.finalPoint == "")
                {
                    return emptyInd;
                }
                p = p->next;
                emptyInd++;
            }
        }

        const int primeKey = 31;

        using ull = unsigned long long;

        ull hash(std::string s)
        {
            ull hashCode = 0;
            for (int i = 0; i < s.length(); ++i)
            {
                hashCode += s[i] * std::pow(primeKey, i);
            }
            return hashCode;
        }

        auto findMin(std::string sign)
        {
            elem *p = first;
            int minVal = 1e9;
            if (sign == "cost")
            {
                while (p)
                {
                    if (p->val.cost < minVal)
                    {
                        minVal = p->val.cost;
                    }
                    p = p->next;
                }
                return minVal;
            }
            if (sign == "final point")
            {
                std::string ans = "";
                while (p)
                {
                    if (p->val.finalPoint < minVal)
                    {
                        ans = p->val.finalPoint;
                    }
                    p = p->next;
                }
                return ans;
            }
            if (sign == "flight number")
            {
                while (p)
                {
                    if (p->val.flightNumber < minVal)
                    {
                        minVal = p->val.flightNumber;
                    }
                    p = p->next;
                }
                return minVal;
            }
            if (sign == "number of departure")
            {
                while (p)
                {
                    if (p->val.cost < minVal)
                    {
                        minVal = p->val.cost;
                    }
                    p = p->next;
                }
                return minVal;
            }
            if (sign == "sit number")
            {
                while (p)
                {
                    if (p->val.sitNumber < minVal)
                    {
                        minVal = p->val.sitNumber;
                    }
                    p = p->next;
                }
                return minVal;
            }
            if (sign == "day")
            {
                while (p)
                {
                    if (p->val.data.day < minVal)
                    {
                        minVal = p->val.data.day;
                    }
                    p = p->next;
                }
                return minVal;
            }
            if (sign == "mounth")
            {
                while (p)
                {
                    if (p->val.data.mounth < minVal)
                    {
                        minVal = p->val.data.mounth;
                    }
                    p = p->next;
                }
                return minVal;
            }
            if (sign == "year")
            {
                while (p)
                {
                    if (p->val.data.year < minVal)
                    {
                        minVal = p->val.data.year;
                    }
                    p = p->next;
                }
                return minVal;
            }
        }

        auto find_nearest(std::string sign, auto value)
        {
            int nearestVal = 0;
            ull minDifference = 1e9;
            elem *p = first;
            if (sign == "cost")
            {
                nearestVal = p->val.cost;
                while (p)
                {
                    if (minDifference == 0)
                    {
                        break;
                    }
                    if (abs(value - p->val.cost) < minDifference)
                    {
                        minDifference = abs(value - p->val.cost);
                        nearestVal = p->val.cost;
                    }
                    p = p->next;
                }
                return nearestVal;
            }
            if (sign == "final point")
            {
                std::string ans = "";
                while (p)
                {
                    if (minDifference == 0)
                    {
                        break;
                    }
                    if (abs(hash(value) - hash(p->val.finalPoint)) < minDifference)
                    {
                        minDifference = abs(hash(value) - hash(p->val.finalPoint));
                        ans = p->val.finalPoint;
                    }
                    p = p->next;
                }
                return ans;
            }
            if (sign == "flight number")
            {
                nearestVal = p->val.flightNumber;
                while (p)
                {
                    if (minDifference == 0)
                    {
                        break;
                    }
                    if (abs(p->val.flightNumber - value) < minDifference)
                    {
                        minDifference = abs(p->val.flightNumber - value);
                        nearestVal = p->val.flightNumber;
                    }
                    p = p->next;
                }
                return nearestVal;
            }
            if (sign == "number of departure")
            {
                nearestVal = p->val.numberDeparture;
                while (p)
                {
                    if (minDifference == 0)
                    {
                        break;
                    }
                    if (abs(value - p->val.numberDeparture) < minDifference)
                    {
                        minDifference = abs(value - p->val.numberDeparture);
                        nearestVal = p->val.numberDeparture;
                    }
                    p = p->next;
                }
                return nearestVal;
            }
            if (sign == "sit number")
            {
                nearestVal = p->val.sitNumber;
                while (p)
                {
                    if (minDifference == 0)
                    {
                        break;
                    }
                    if (abs(value - p->val.sitNumber) < minDifference)
                    {
                        minDifference = abs(value - p->val.sitNumber);
                        nearestVal = p->val.sitNumber;
                    }
                    p = p->next;
                }
                return nearestVal;
            }
            if (sign == "day")
            {
                nearestVal = p->val.data.day;
                while (p)
                {
                    if (minDifference == 0)
                    {
                        break;
                    }
                    if (abs(value - p->val.data.day) < minDifference)
                    {
                        minDifference = abs(value - p->val.data.day);
                        nearestVal = p->val.data.day;
                    }
                    p = p->next;
                }
                return nearestVal;
            }
            if (sign == "mounth")
            {
                nearestVal = p->val.data.mounth;
                while (p)
                {
                    if (minDifference == 0)
                    {
                        break;
                    }
                    if (abs(value - p->val.data.mounth) < minDifference)
                    {
                        minDifference = abs(value - p->val.data.mounth);
                        nearestVal = p->val.data.mounth;
                    }
                    p = p->next;
                }
                return nearestVal;
            }
            if (sign == "year")
            {
                nearestVal = p->val.data.year;
                while (p)
                {
                    if (minDifference == 0)
                    {
                        break;
                    }
                    if (p->val.data.year < minDifference)
                    {
                        minDifference = abs(value - p->val.data.year);
                        nearestVal = p->val.data.year;
                    }
                    p = p->next;
                }
                return nearestVal;
            }
        }
    };

    bool cmp(elem *a, elem *b, std::string sign)
    {
        if (sign == "cost")
        {
            return a->val.cost < b->val.cost;
        }
        if (sign == "final point")
        {
            return a->val.finalPoint < b->val.finalPoint;
        }
        if (sign == "flight number")
        {
            return a->val.flightNumber < b->val.flightNumber;
        }
        if (sign == "number of departure")
        {
            return a->val.numberDeparture < b->val.numberDeparture;
        }
        if (sign == "sit number")
        {
            return a->val.sitNumber < b->val.sitNumber;
        }
        if (sign == "day")
        {
            return a->val.data.day < b->val.data.day;
        }
        if (sign == "mounth")
        {
            return a->val.data.mounth < b->val.data.mounth;
        }
        if (sign == "year")
        {
            return a->val.data.year < b->val.data.year;
        }
        return false;
    }

    std::string sign; // признак сортировки

    elem *swap(elem *ptr1, elem *ptr2)
    {
        elem *tmp = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = tmp;
        return ptr2;
    }

    void bubbleSort(elem **head, int n)
    {
        elem **h;
        int swapped = 0;
        for (int i = 0; i < n; ++i)
        {
            h = head;
            swapped = 0;
            for (int j = 0; j < n; ++i)
            {
                elem *p1 = *h;
                elem *p2 = p1->next;
                if (!cmp(p1, p2, sign))
                {
                    *h = swap(p1, p2);
                    swapped = 1;
                }
                h = &(*h)->next;
            }
            if (swapped == 0)
            {
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // ТЕСТЫ................................... :)
    return 0;
}