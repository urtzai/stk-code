//  $Id$
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2006 SuperTuxKart-Team
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_CHARSEL_H
#define HEADER_CHARSEL_H

#include <vector>
#include "base_gui.hpp"

class ssgTransform;
class ssgContext;

class CharSel: public BaseGUI
{
private:
    ssgContext      *m_context;
    ssgTransform    *m_kart;
    int              m_current_kart;
    float            m_clock;
    int              m_player_index;
    int              m_offset;        // index of first racer displayed
    unsigned int     m_num_entries;   // number of entries to display
    std::vector<int> m_indexAvailKart;
    
    bool             kartAvailable(int kart);
    void             updateScrollPosition();
    int              computeIndent(int n) {return 40+abs((m_num_entries-1)/2 - n)*3;}
public:
    CharSel(int which_player);
    ~CharSel();

    void switchCharacter(int n);
    void update(float dt);
    void select();
};

#endif
