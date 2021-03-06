/*
===========================================================================
    Copyright (C) riicchhaarrd
    Copyright (C) 1999-2005 Id Software, Inc.

    This file is part of CoDExtended source code.

    CoDExtended source code is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CoDExtended source code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
===========================================================================
*/

#include "Entity.hpp"

int Entity::getPlayerState() {
    if(base == NULL)
        return NULL;
    return *(int*)(base+EOFF.PLAYERSTATE);
}

void Entity::switchState() {
    if(ps)
        this->ptr = this->getPlayerState();
    else
        this->ptr = this->base;
    ps = !ps;
}

void Entity::toPlayerState() {
    this->ptr = this->getPlayerState();
    ps = true;
}

void Entity::toEntityState() {
    this->ptr = this->base;
    ps = false;
}
