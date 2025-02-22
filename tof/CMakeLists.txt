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

# Create a library called "libR3BCal" which includes the source files given in
# the array. The extension is already found. Any number of sources could be
# listed here.

Set(SYSTEM_INCLUDE_DIRECTORIES 
${SYSTEM_INCLUDE_DIRECTORIES}
${BASE_INCLUDE_DIRECTORIES}
)

set(INCLUDE_DIRECTORIES
#put here all directories where header files are located
${R3BROOT_SOURCE_DIR}/r3bbase
${R3BROOT_SOURCE_DIR}/tof
${R3BROOT_SOURCE_DIR}/los
${R3BROOT_SOURCE_DIR}/tcal
${R3BROOT_SOURCE_DIR}/r3bdata
${R3BROOT_SOURCE_DIR}/r3bdata/losData
${R3BROOT_SOURCE_DIR}/r3bdata/mtofData
${R3BROOT_SOURCE_DIR}/r3bdata/tofData
${R3BROOT_SOURCE_DIR}/r3bdata/ptofData
${R3BROOT_SOURCE_DIR}/r3bdata/neulandData
${R3BROOT_SOURCE_DIR}/tracking
)

include_directories( ${INCLUDE_DIRECTORIES})
include_directories(SYSTEM ${SYSTEM_INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES
${ROOT_LIBRARY_DIR}
${FAIRROOT_LIBRARY_DIR}
) 

link_directories( ${LINK_DIRECTORIES})

set(SRCS
#Put here your sourcefiles
R3BTof.cxx  
R3BGeoTof.cxx   
R3BGeoTofPar.cxx   
R3BTofContFact.cxx 
R3BTofDigiPar.cxx
R3BTofDigitizer.cxx
R3BTof2pDigiPar.cxx
R3BTof2pDigitizer.cxx  
R3BTofdMapped2Cal.cxx
R3BTofdMapped2CalPar.cxx
R3BTofdCal2HitPar.cxx
R3BTofdCal2Histo.cxx
R3BTofdCal2HistoPar.cxx
R3BTofdChangePar.cxx
R3BTofdCal2Hit.cxx
R3BTofdCal2HitS454.cxx
R3BTofdCal2HitS494.cxx
R3BTofdHitModulePar.cxx
R3BTofdHitPar.cxx
R3BTofd.cxx
R3BTofdDigitizer.cxx
R3BTofdDigitizerCal.cxx
R3BGeoTofd.cxx   
R3BGeoTofdPar.cxx   
R3BTofdContFact.cxx 
R3BTofdDigiPar.cxx
R3BPtofMapped2CalPar.cxx
R3BPtofMapped2Cal.cxx
calibration/R3BPtofCal2HitPar.cxx
calibration/R3BPtofCal2Hit.cxx
calibration/R3BPtofHitPar.cxx
calibration/R3BPtofParFact.cxx
)

# fill list of header files from list of source files
# by exchanging the file extension
CHANGE_FILE_EXTENSION(*.cxx *.h HEADERS "${SRCS}")

set(LINKDEF TofLinkDef.h)
set(LIBRARY_NAME R3BTof)
set(DEPENDENCIES
    Spectrum R3BBase R3BTracking R3BData R3BTCal)
    
GENERATE_LIBRARY()
