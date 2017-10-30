#pragma once
struct Datum
{
public:
	Datum(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	int day;
	int month;
	int year;
};