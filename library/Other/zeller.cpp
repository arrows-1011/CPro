/*
  年月日を指定して
  曜日計算をO(1)でする。

  0: 日曜日
  1: 月曜日
  2: 火曜日
  3: 水曜日
  4: 木曜日
  5: 金曜日
  6: 土曜日
*/

#include <iostream>

using namespace std;

int zeller(int Y, int M, int D)
{
    if (M < 3) {
	Y--;
	M += 12;
    }
    return (Y + Y / 4 - Y / 100 + Y / 400 + (13 * M + 8) / 5 + D) % 7;
}
