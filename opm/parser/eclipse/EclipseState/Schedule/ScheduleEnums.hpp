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

#ifndef SCHEDULE_ENUMS_H
#define SCHEDULE_ENUMS_H

#include <string>
#include <stdexcept>

namespace Opm {
    enum CompletionStateEnum {
        OPEN = 1,
        SHUT = 2,
        AUTO = 3
    };


    enum PhaseEnum {
        OIL   = 1,
        GAS   = 2,
        WATER = 4
    };



    const std::string CompletionStateEnum2String( CompletionStateEnum enumValue );
    CompletionStateEnum CompletionStateEnumFromString( const std::string& stringValue );

    const std::string PhaseEnum2String( PhaseEnum enumValue );
    PhaseEnum PhaseEnumFromString( const std::string& stringValue );
    
}

#endif
