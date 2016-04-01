#include <iostream>
#include <string>

#include "Fish.h"
#include "FishTank.h"

using namespace std;

Fish::Fish()
{
	// initialize all values to zero/empty string
    	img_hgt = 0;
	img_wid = 0;
	pos_vert = 0.0;
	pos_horz = 0.0;
	speed_vert = 0.0;
	speed_horz = 0.0;
	name = "";

	// initialize fish image with all spaces
	for (int i=0;i<MAX_HGT;i++){
		for (int j=0;j<MAX_WID;j++){
		    image[i][j] = ' ';
		}
	}
}

bool Fish::readFish()
{
	string test, line, blank_line;
	cin >> test;
	// tests that first word/input is in fact 'fish'
	if (test != "fish") {
		return false;
	}

	cin >> img_hgt >> img_wid >> pos_vert >> pos_horz
	    >> speed_vert >> speed_horz >> name;
	getline(cin, blank_line); // cin rest of first line (should be blank)
	
	for (int i=0;i<img_hgt;i++){
	    getline(cin, line);
	    for (int j=0;j<img_wid;j++){
		if (j >= line.length())   // if no more characters are present
		    image[i][j] = ' ';    // add spaces to fish image (until max)
		else
		    image[i][j] = line[j];
	    }
	}

	// if any of the following occur (too big, too small, end of file, etc)
	// return false (signifying the fish was not properly read in
	// and will therefore not be added to the fish_holder array
	if ((cin.fail()) || (img_hgt < 0) || (img_hgt > MAX_HGT) ||
	    (img_wid < 0) || (img_wid > MAX_WID))
	    return false;
	
	return true;
}

string Fish::getName()
{
    	return name;
}

void Fish::setName(string new_name)
{
    	name = new_name;
}

void Fish::setHSpeed(float new_speed)
{
	speed_horz = new_speed;
} 

void Fish::setVSpeed(float new_speed)
{
	speed_vert = new_speed;
}

void Fish::setPos(int row, int col)
{
	pos_vert = row;
	pos_horz = col;
}

int Fish::getHeight()
{
    return img_hgt;
}

int Fish::getWidth()
{
    return img_wid;
}

void Fish::move(int tankHeight, int tankWidth)
{
    pos_vert += speed_vert;
    pos_horz += speed_horz;
    
    // if position is outside of the bounds of the tank,
    // re-position it properly
    if (pos_vert <= -img_hgt)
	pos_vert = tankHeight - img_hgt;
    else if (pos_vert >= tankHeight)
	pos_vert = 0;
    else if (pos_horz <= -img_wid)
	pos_horz = tankWidth - img_wid;
    else if (pos_horz >= tankWidth)
	pos_horz = 0;
}

void Fish::draw(FishTank *p_tank)
{
    int tHeight = p_tank->getHeight();
    int tWidth  = p_tank->getWidth();
    
    // loops through ever element of fish image
    for (int i=0;i<img_hgt;i++){
    	for (int j=0;j<img_wid;j++){
    	    int x_pos = pos_horz + j;
    	    int y_pos = pos_vert + i;
		if (image[i][j] != ' '){ // doesn't print spaces
		    // compensates if part of image is outside of tank bounds
		    if (pos_vert+i >= tHeight)
			y_pos = pos_vert + i - tHeight;
		    if (pos_vert+i < 0)
			y_pos = tHeight+(pos_vert + i);
		    if (pos_horz+j >= tWidth)
			x_pos = pos_horz + j - tWidth;
		    if (pos_horz+j < 0)
			x_pos = tWidth+(pos_horz + j);

	            p_tank->UpdateAt(y_pos,x_pos,image[i][j]);
		}
	}
    }
}