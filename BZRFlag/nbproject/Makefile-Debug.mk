#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/693638321/Lab1_Main.o \
	${OBJECTDIR}/_ext/693638321/TeamAI.o \
	${OBJECTDIR}/_ext/693638321/PotentialFieldCalculator.o \
	${OBJECTDIR}/_ext/693638321/PDController.o \
	${OBJECTDIR}/_ext/693638321/TankAI.o \
	${OBJECTDIR}/_ext/693638321/DumbTeamAI.o \
	${OBJECTDIR}/_ext/693638321/DumbTankAI.o \
	${OBJECTDIR}/_ext/693638321/TankVector.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bzrflag

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bzrflag: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bzrflag ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/693638321/Lab1_Main.o: ../BZRFlag\ AI/Lab1_Main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/Lab1_Main.o ../BZRFlag\ AI/Lab1_Main.cpp

${OBJECTDIR}/_ext/693638321/TeamAI.o: ../BZRFlag\ AI/TeamAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/TeamAI.o ../BZRFlag\ AI/TeamAI.cpp

${OBJECTDIR}/_ext/693638321/PotentialFieldCalculator.o: ../BZRFlag\ AI/PotentialFieldCalculator.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/PotentialFieldCalculator.o ../BZRFlag\ AI/PotentialFieldCalculator.cpp

${OBJECTDIR}/_ext/693638321/PDController.o: ../BZRFlag\ AI/PDController.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/PDController.o ../BZRFlag\ AI/PDController.cpp

${OBJECTDIR}/_ext/693638321/TankAI.o: ../BZRFlag\ AI/TankAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/TankAI.o ../BZRFlag\ AI/TankAI.cpp

${OBJECTDIR}/_ext/693638321/DumbTeamAI.o: ../BZRFlag\ AI/DumbTeamAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/DumbTeamAI.o ../BZRFlag\ AI/DumbTeamAI.cpp

${OBJECTDIR}/_ext/693638321/DumbTankAI.o: ../BZRFlag\ AI/DumbTankAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/DumbTankAI.o ../BZRFlag\ AI/DumbTankAI.cpp

${OBJECTDIR}/_ext/693638321/TankVector.o: ../BZRFlag\ AI/TankVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/TankVector.o ../BZRFlag\ AI/TankVector.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bzrflag

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
