/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!
**
**********************************************************************/


#ifndef RS_VECTOR_H
#define RS_VECTOR_H

#include <iostream>
#include <cmath>
#include "rs_math.h"

/**
 * Represents a 3d vector (x/y/z)
 *
 * @author Andrew Mustun
 */
class RS_Vector {
public:
    RS_Vector();
#ifdef  RS_VECTOR2D
    RS_Vector(double vx, double vy);
#else
    RS_Vector(double vx, double vy, double vz=0.0);
#endif
    RS_Vector(double angle);
    //RS_Vector(double v[]);
    explicit RS_Vector(bool valid);
    ~RS_Vector();

    void set(double angle); // set to unit vector by the direction of angle
#ifdef  RS_VECTOR2D
    void set(double vx, double vy);
#else
    void set(double vx, double vy, double vz=0.0);
#endif
    void setPolar(double radius, double angle);

    double distanceTo(const RS_Vector& v) const;
    double angle() const;
    double angleTo(const RS_Vector& v) const;
    double angleBetween(const RS_Vector& v1, const RS_Vector& v2) const;
    double magnitude() const;
    double squared() const; //return square of length
    RS_Vector lerp(const RS_Vector& v, double t) const;

    bool isInWindow(const RS_Vector& firstCorner, const RS_Vector& secondCorner);
    bool isInWindowOrdered(const RS_Vector& vLow, const RS_Vector& vHigh);

    RS_Vector toInteger();

    RS_Vector move(const RS_Vector& offset);
    RS_Vector rotate(const double& ang);
    RS_Vector rotate(const RS_Vector& angleVector);
    RS_Vector rotate(const RS_Vector& center, const double& ang);
    RS_Vector rotate(const RS_Vector& center, const RS_Vector& angleVector);
    RS_Vector scale(const double& factor);
    RS_Vector scale(const RS_Vector& factor);
    RS_Vector scale(const RS_Vector& center, const RS_Vector& factor);
    RS_Vector mirror(const RS_Vector& axisPoint1, const RS_Vector& axisPoint2);

    RS_Vector operator + (const RS_Vector& v) const;
    RS_Vector operator - (const RS_Vector& v) const;
    RS_Vector operator * (const double& s) const;
    RS_Vector operator / (const double& s) const;
    RS_Vector operator - () const;

    void operator += (const RS_Vector& v);
    void operator -= (const RS_Vector& v);
    void operator *= (const double& s);
    void operator /= (const double& s);

    bool operator == (const RS_Vector& v) const;
    bool operator != (const RS_Vector& v) const {
        return !operator==(v);
    }

    static RS_Vector minimum(const RS_Vector& v1, const RS_Vector& v2);
    static RS_Vector maximum(const RS_Vector& v1, const RS_Vector& v2);
#ifndef RS_VECTOR2D
//    crossP only defined for 3D
    static RS_Vector crossP(const RS_Vector& v1, const RS_Vector& v2);
#endif
    static double dotP(const RS_Vector& v1, const RS_Vector& v2);

    friend std::ostream& operator << (std::ostream&, const RS_Vector& v);

#ifdef RS_TEST

    static bool test();
#endif

public:
    double x;
    double y;
#ifndef RS_VECTOR2D
    double z;
#endif
    bool valid;
};


/**
 * Represents one to 4 vectors. Typically used to return multiple
 * solutions from a function.
 */

#endif

// EOF
