#pragma once

enum PriceType { GENERAL=1, VIP, DISCOUNT };

class Ticket {
private:
	int id;
	const char* event;
	PriceType type;
	int price;
	bool isValid;

public:
};