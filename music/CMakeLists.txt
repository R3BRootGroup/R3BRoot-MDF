##############################################################################
#   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    #
#   Copyright (C) 2019 Members of R3B Collaboration                          #
#                                                                            #
#             This software is distributed under the terms of the            #
#                 GNU General Public Licence (GPL) version 3,                #
#                    copied verbatim in the file "LICENSE".                  #
#                                                                            #
# In applying this license GSI does not waive the privileges and immunities  #
# granted to it by virtue of its status as an Intergovernmental Organization #
# or submit itself to any jurisdiction.                                      #
##############################################################################

# Create a library called "libR3BMusic" which includes the source files given
# in the array. The extension is already found. Any number of sources could be
# listed here.

Set(SYSTEM_INCLUDE_DIRECTORIES
${SYSTEM_INCLUDE_DIRECTORIES}
${BASE_INCLUDE_DIRECTORIES}
)

set(INCLUDE_DIRECTORIES
#put here all directories where header files are located
${R3BROOT_SOURCE_DIR}/r3bbase
${R3BROOT_SOURCE_DIR}/music
${R3BROOT_SOURCE_DIR}/music/online
${R3BROOT_SOURCE_DIR}/music/pars
${R3BROOT_SOURCE_DIR}/music/calibration
${R3BROOT_SOURCE_DIR}/music/sim
${R3BROOT_SOURCE_DIR}/tracking
${R3BROOT_SOURCE_DIR}/r3bdata
${R3BROOT_SOURCE_DIR}/r3bdata/musicData
${R3BROOT_SOURCE_DIR}/r3bdata/mwpcData
${R3BROOT_SOURCE_DIR}/r3bdata/losData
)

include_directories( ${INCLUDE_DIRECTORIES})
include_directories(SYSTEM ${SYSTEM_INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES ${ROOT_LIBRARY_DIR} ${FAIRROOT_LIBRARY_DIR} )

link_directories( ${LINK_DIRECTORIES})

set(SRCS
#Put here your sourcefiles
#./sim/R3BMusic.cxx
#./sim/R3BMusicDigitizer.cxx
#./pars/R3BMusicCalPar.cxx
#./pars/R3BMusicHitPar.cxx
#./pars/R3BMusicContFact.cxx
#./pars/R3BMusicMapped2CalPar.cxx
#./pars/R3BMusicMapped2CalPar_S515.cxx
#./calibration/R3BMusicMapped2Cal.cxx
#./calibration/R3BMusicCal2Hit.cxx
#./online/R3BMusicOnlineSpectra.cxx
#./sim/R3BMusic.cxx
#./sim/R3BMusicDigitizer.cxx
#./pars/R3BMusicCalPar.cxx
#./pars/R3BMusicHitPar.cxx
#./pars/R3BMusicContFact.cxx
#./pars/R3BMusicMapped2CalPar.cxx
#./calibration/R3BMusicMapped2Cal.cxx
#./calibration/R3BMusicCal2Hit.cxx
#./online/R3BMusicOnlineSpectra.cxx
)

file(GLOB SRCS
./sim/*.cxx
./pars/*.cxx
./calibration/*.cxx
./online/*.cxx
)

# fill list of header files from list of source files
# by exchanging the file extension
CHANGE_FILE_EXTENSION(*.cxx *.h HEADERS "${SRCS}")

set(LINKDEF MusicLinkDef.h)
set(LIBRARY_NAME R3BMusic)
set(DEPENDENCIES
          R3BBase R3BData R3BTracking)

GENERATE_LIBRARY()
