/**************************************************************************
    Lightspark, a free flash player implementation

    Copyright (C) 2009-2011  Alessandro Pignotti (a.pignotti@sssup.it)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/

//#include "abc.h"
//#include "flashgeom.h"
//#include "class.h"

void flashgeom::rotate(Matrix *h,number_t angle)
{
        number_t ta, tb, tc, td;

        ta = th->a * ca + th->c * sa;
        tb = th->b * ca + th->d * sa;
        tc = th->c * ca - th->a * sa;
        td = th->d * ca - th->b * sa;

        th->a = ta;
        th->b = tb;
        th->c = tc;
        th->d = td;

}

