/*
  Copyright 2013 Statoil ASA.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>

#include <opm/parser/eclipse/Deck/DeckItem.hpp>
#include <opm/parser/eclipse/Deck/DeckKeyword.hpp>
#include <opm/parser/eclipse/Deck/DeckRecord.hpp>
#include <opm/parser/eclipse/Parser/ParseContext.hpp>
#include <opm/parser/eclipse/EclipseState/Eclipse3DProperties.hpp>
#include <opm/parser/eclipse/EclipseState/Grid/EclipseGrid.hpp>
#include <opm/parser/eclipse/EclipseState/Schedule/Connection.hpp>
#include <opm/parser/eclipse/EclipseState/Schedule/ScheduleEnums.hpp>
#include <opm/parser/eclipse/EclipseState/Schedule/Well.hpp>
#include <opm/parser/eclipse/EclipseState/Schedule/Schedule.hpp>
#include <opm/parser/eclipse/EclipseState/Util/Value.hpp>

namespace Opm {

    Connection::Connection(int i, int j , int k ,
                           int compnum,
                           double depth,
                           WellCompletion::StateEnum state ,
                           const Value<double>& connectionTransmissibilityFactor,
                           const Value<double>& diameter,
                           const Value<double>& skinFactor,
                           const int satTableId,
                           const WellCompletion::DirectionEnum direction)
        : m_i(i), m_j(j), m_k(k),
          complnum( compnum ),
          m_diameter(diameter),
          m_connectionTransmissibilityFactor(connectionTransmissibilityFactor),
          wellPi(1.0),
          m_skinFactor(skinFactor),
          sat_tableId(satTableId),
          state(state),
          dir(direction),
          center_depth( depth )
    {}

    bool Connection::sameCoordinate(const int i, const int j, const int k) const {
        if ((m_i == i) && (m_j == j) && (m_k == k)) {
            return true;
        } else {
            return false;
        }
    }



    int Connection::getI() const {
        return m_i;
    }

    int Connection::getJ() const {
        return m_j;
    }

    int Connection::getK() const {
        return m_k;
    }


    double Connection::getConnectionTransmissibilityFactor() const {
        return m_connectionTransmissibilityFactor.getValue();
    }

    double Connection::getDiameter() const {
        return m_diameter.getValue();
    }

    double Connection::getSkinFactor() const {
        return m_skinFactor.getValue();
    }


    const Value<double>& Connection::getConnectionTransmissibilityFactorAsValueObject() const {
        return m_connectionTransmissibilityFactor;
    }
    bool Connection::attachedToSegment() const {
        return (segment_number > 0);
    }

    bool Connection::operator==( const Connection& rhs ) const {
        return this->m_i == rhs.m_i
            && this->m_j == rhs.m_j
            && this->m_k == rhs.m_k
            && this->complnum == rhs.complnum
            && this->m_diameter == rhs.m_diameter
            && this->m_connectionTransmissibilityFactor
                            == rhs.m_connectionTransmissibilityFactor
            && this->wellPi == rhs.wellPi
            && this->m_skinFactor == rhs.m_skinFactor
            && this->sat_tableId == rhs.sat_tableId
            && this->state == rhs.state
            && this->dir == rhs.dir
            && this->segment_number == rhs.segment_number
            && this->center_depth == rhs.center_depth;
    }

    bool Connection::operator!=( const Connection& rhs ) const {
        return !( *this == rhs );
    }
}


