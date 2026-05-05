/*2451454 电信 杨翰卓*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int DATE_WIDTH = 4;               // 每个日期宽度
const int DAYS_IN_WEEK = 7;
const string WEEKDAYS = "Sun Mon Tue Wed Thu Fri Sat";


// 获取某年某月1号是星期几
int getFirstWeekday(int year, int month) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int c = year / 100;
    int y = year % 100;
    int w = (y + y / 4 + c / 4 - 2 * c + (13 * (month + 1)) / 5 + 1) % 7;
    return (w + 7) % 7;
}

// 判断是否闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 每月天数
int getMonthDays(int year, int month) {
    static int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && isLeapYear(year)) return 29;
    return monthDays[month - 1];
}

// 打印一行中的月份标题（居中）
void printMonthTitles(int startMonth, int count) {
    for (int i = 0; i < count; ++i) {
        string title = to_string(startMonth + i) + "月";
        int totalWidth = DATE_WIDTH * DAYS_IN_WEEK;
        int leftPad = (totalWidth - title.size()) / 2;
        cout << string(leftPad, ' ') << title << string(totalWidth - leftPad - title.size(), ' ');
        if (i < count - 1) cout << "    "; // 每组之间空一格
    }
    cout << endl;
}

// 打印一行中的星期标题（左对齐）
void printWeekHeaders(int count) {
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < DAYS_IN_WEEK; ++j)
            cout << setw(DATE_WIDTH) << left << WEEKDAYS.substr(j * 4, 3);
        if (i < count - 1) cout << "    ";
    }
    cout << endl;
}

// 打印该周所有月的日期
void printWeekRows(int year, int startMonth, int count) {
    int monthStart[12], monthDay[12], dayPos[12];

    for (int i = 0; i < count; ++i) {
        int m = startMonth + i;
        monthStart[i] = getFirstWeekday(year, m);
        monthDay[i] = getMonthDays(year, m);
        dayPos[i] = 1;
    }

    bool hasMore = true;
    while (hasMore) {
        hasMore = false;
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < DAYS_IN_WEEK; ++j) {
                if ((dayPos[i] == 1 && j < monthStart[i]) || dayPos[i] > monthDay[i]) {
                    cout << setw(DATE_WIDTH) << " ";
                }
                else {
                    cout << setw(DATE_WIDTH) << left << dayPos[i];
                    dayPos[i]++;
                    hasMore = true;
                }
            }
            if (i < count - 1) cout << "    ";
        }
        cout << endl;
    }
}

int main() {
    int year, monthsPerRow;

    while(1)
    {
        cout << "请输入年份[1900 - 2100]" << endl;
        cin >> year;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (year < 1900 || year>2100)
            continue;
        break;
    }
    while(1)
    {
        cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
        cin >> monthsPerRow;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (monthsPerRow != 1 && monthsPerRow != 2 && monthsPerRow != 3 && monthsPerRow != 4 && monthsPerRow != 6 && monthsPerRow != 12)
            continue;
        break;
    }
    cout << year << "年的日历:" << endl << endl;

    for (int m = 1; m <= 12; m += monthsPerRow) {
        int count = min(monthsPerRow, 12 - m + 1);
        printMonthTitles(m, count);
        printWeekHeaders(count);
        printWeekRows(year, m, count);
        //cout << endl;
    }

    return 0;
}