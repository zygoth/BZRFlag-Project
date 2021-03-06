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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/693638321/Lab1_Main.o \
	${OBJECTDIR}/_ext/693638321/SearchTankAI.o \
	${OBJECTDIR}/_ext/693638321/DepthNode.o \
	${OBJECTDIR}/_ext/693638321/DumbCommanderAI.o \
	${OBJECTDIR}/_ext/693638321/StraightLineTankAI.o \
	${OBJECTDIR}/_ext/693638321/BehaviorTankAI.o \
	${OBJECTDIR}/_ext/693638321/f9.o \
	${OBJECTDIR}/_ext/693638321/EvadeBehavior.o \
	${OBJECTDIR}/_ext/693638321/Point.o \
	${OBJECTDIR}/_ext/693638321/BZRFlagGame.o \
	${OBJECTDIR}/_ext/693638321/GridFilter.o \
	${OBJECTDIR}/_ext/693638321/PotentialFieldCalculator.o \
	${OBJECTDIR}/_ext/693638321/DFSArraySearcher.o \
	${OBJECTDIR}/_ext/693638321/PDController.o \
	${OBJECTDIR}/_ext/693638321/TargetPointCalculator.o \
	${OBJECTDIR}/_ext/693638321/CaptureBehavior.o \
	${OBJECTDIR}/_ext/693638321/BFSArraySearcher.o \
	${OBJECTDIR}/_ext/693638321/PotentialFieldCommanderAI.o \
	${OBJECTDIR}/_ext/693638321/EvaderCommanderAI.o \
	${OBJECTDIR}/_ext/693638321/UniformCostArraySearcher.o \
	${OBJECTDIR}/_ext/693638321/CommanderAI.o \
	${OBJECTDIR}/_ext/693638321/PotentialFieldPrinter.o \
	${OBJECTDIR}/_ext/693638321/Behavior.o \
	${OBJECTDIR}/_ext/693638321/CornerCalculator.o \
	${OBJECTDIR}/_ext/693638321/EvaderTankAI.o \
	${OBJECTDIR}/_ext/693638321/TankAI.o \
	${OBJECTDIR}/_ext/693638321/DefendBehavior.o \
	${OBJECTDIR}/_ext/693638321/GoToBehavior.o \
	${OBJECTDIR}/_ext/693638321/BehaviorCommanderAI.o \
	${OBJECTDIR}/_ext/693638321/GNUPrinter.o \
	${OBJECTDIR}/_ext/693638321/Node.o \
	${OBJECTDIR}/_ext/693638321/ShooterTankAI.o \
	${OBJECTDIR}/_ext/693638321/SearchCommanderAI.o \
	${OBJECTDIR}/_ext/693638321/ShooterCommanderAI.o \
	${OBJECTDIR}/_ext/693638321/PotentialFieldTankAI.o \
	${OBJECTDIR}/_ext/693638321/StraightLineCommanderAI.o \
	${OBJECTDIR}/_ext/693638321/DumbTankAI.o \
	${OBJECTDIR}/_ext/693638321/IDArraySearcher.o \
	${OBJECTDIR}/_ext/693638321/DepthLimitedArraySearcher.o \
	${OBJECTDIR}/_ext/693638321/SearchTools.o \
	${OBJECTDIR}/_ext/693638321/TankTargeter.o \
	${OBJECTDIR}/_ext/693638321/TankVector.o \
	${OBJECTDIR}/_ext/693638321/BZRCTools.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lrt
CXXFLAGS=-lrt

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
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/Lab1_Main.o ../BZRFlag\ AI/Lab1_Main.cpp

${OBJECTDIR}/_ext/693638321/SearchTankAI.o: ../BZRFlag\ AI/SearchTankAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/SearchTankAI.o ../BZRFlag\ AI/SearchTankAI.cpp

${OBJECTDIR}/_ext/693638321/DepthNode.o: ../BZRFlag\ AI/DepthNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/DepthNode.o ../BZRFlag\ AI/DepthNode.cpp

${OBJECTDIR}/_ext/693638321/DumbCommanderAI.o: ../BZRFlag\ AI/DumbCommanderAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/DumbCommanderAI.o ../BZRFlag\ AI/DumbCommanderAI.cpp

${OBJECTDIR}/_ext/693638321/StraightLineTankAI.o: ../BZRFlag\ AI/StraightLineTankAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/StraightLineTankAI.o ../BZRFlag\ AI/StraightLineTankAI.cpp

${OBJECTDIR}/_ext/693638321/BehaviorTankAI.o: ../BZRFlag\ AI/BehaviorTankAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/BehaviorTankAI.o ../BZRFlag\ AI/BehaviorTankAI.cpp

${OBJECTDIR}/_ext/693638321/f9.o: ../BZRFlag\ AI/f9.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/f9.o ../BZRFlag\ AI/f9.cpp

${OBJECTDIR}/_ext/693638321/EvadeBehavior.o: ../BZRFlag\ AI/EvadeBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/EvadeBehavior.o ../BZRFlag\ AI/EvadeBehavior.cpp

${OBJECTDIR}/_ext/693638321/Point.o: ../BZRFlag\ AI/Point.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/Point.o ../BZRFlag\ AI/Point.cpp

${OBJECTDIR}/_ext/693638321/BZRFlagGame.o: ../BZRFlag\ AI/BZRFlagGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/BZRFlagGame.o ../BZRFlag\ AI/BZRFlagGame.cpp

${OBJECTDIR}/_ext/693638321/GridFilter.o: ../BZRFlag\ AI/GridFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/GridFilter.o ../BZRFlag\ AI/GridFilter.cpp

${OBJECTDIR}/_ext/693638321/PotentialFieldCalculator.o: ../BZRFlag\ AI/PotentialFieldCalculator.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/PotentialFieldCalculator.o ../BZRFlag\ AI/PotentialFieldCalculator.cpp

${OBJECTDIR}/_ext/693638321/DFSArraySearcher.o: ../BZRFlag\ AI/DFSArraySearcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/DFSArraySearcher.o ../BZRFlag\ AI/DFSArraySearcher.cpp

${OBJECTDIR}/_ext/693638321/PDController.o: ../BZRFlag\ AI/PDController.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/PDController.o ../BZRFlag\ AI/PDController.cpp

${OBJECTDIR}/_ext/693638321/TargetPointCalculator.o: ../BZRFlag\ AI/TargetPointCalculator.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/TargetPointCalculator.o ../BZRFlag\ AI/TargetPointCalculator.cpp

${OBJECTDIR}/_ext/693638321/CaptureBehavior.o: ../BZRFlag\ AI/CaptureBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/CaptureBehavior.o ../BZRFlag\ AI/CaptureBehavior.cpp

${OBJECTDIR}/_ext/693638321/BFSArraySearcher.o: ../BZRFlag\ AI/BFSArraySearcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/BFSArraySearcher.o ../BZRFlag\ AI/BFSArraySearcher.cpp

${OBJECTDIR}/_ext/693638321/PotentialFieldCommanderAI.o: ../BZRFlag\ AI/PotentialFieldCommanderAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/PotentialFieldCommanderAI.o ../BZRFlag\ AI/PotentialFieldCommanderAI.cpp

${OBJECTDIR}/_ext/693638321/EvaderCommanderAI.o: ../BZRFlag\ AI/EvaderCommanderAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/EvaderCommanderAI.o ../BZRFlag\ AI/EvaderCommanderAI.cpp

${OBJECTDIR}/_ext/693638321/UniformCostArraySearcher.o: ../BZRFlag\ AI/UniformCostArraySearcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/UniformCostArraySearcher.o ../BZRFlag\ AI/UniformCostArraySearcher.cpp

${OBJECTDIR}/_ext/693638321/CommanderAI.o: ../BZRFlag\ AI/CommanderAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/CommanderAI.o ../BZRFlag\ AI/CommanderAI.cpp

${OBJECTDIR}/_ext/693638321/PotentialFieldPrinter.o: ../BZRFlag\ AI/PotentialFieldPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/PotentialFieldPrinter.o ../BZRFlag\ AI/PotentialFieldPrinter.cpp

${OBJECTDIR}/_ext/693638321/Behavior.o: ../BZRFlag\ AI/Behavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/Behavior.o ../BZRFlag\ AI/Behavior.cpp

${OBJECTDIR}/_ext/693638321/CornerCalculator.o: ../BZRFlag\ AI/CornerCalculator.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/CornerCalculator.o ../BZRFlag\ AI/CornerCalculator.cpp

${OBJECTDIR}/_ext/693638321/EvaderTankAI.o: ../BZRFlag\ AI/EvaderTankAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/EvaderTankAI.o ../BZRFlag\ AI/EvaderTankAI.cpp

${OBJECTDIR}/_ext/693638321/TankAI.o: ../BZRFlag\ AI/TankAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/TankAI.o ../BZRFlag\ AI/TankAI.cpp

${OBJECTDIR}/_ext/693638321/DefendBehavior.o: ../BZRFlag\ AI/DefendBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/DefendBehavior.o ../BZRFlag\ AI/DefendBehavior.cpp

${OBJECTDIR}/_ext/693638321/GoToBehavior.o: ../BZRFlag\ AI/GoToBehavior.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/GoToBehavior.o ../BZRFlag\ AI/GoToBehavior.cpp

${OBJECTDIR}/_ext/693638321/BehaviorCommanderAI.o: ../BZRFlag\ AI/BehaviorCommanderAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/BehaviorCommanderAI.o ../BZRFlag\ AI/BehaviorCommanderAI.cpp

${OBJECTDIR}/_ext/693638321/GNUPrinter.o: ../BZRFlag\ AI/GNUPrinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/GNUPrinter.o ../BZRFlag\ AI/GNUPrinter.cpp

${OBJECTDIR}/_ext/693638321/Node.o: ../BZRFlag\ AI/Node.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/Node.o ../BZRFlag\ AI/Node.cpp

${OBJECTDIR}/_ext/693638321/ShooterTankAI.o: ../BZRFlag\ AI/ShooterTankAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/ShooterTankAI.o ../BZRFlag\ AI/ShooterTankAI.cpp

${OBJECTDIR}/_ext/693638321/SearchCommanderAI.o: ../BZRFlag\ AI/SearchCommanderAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/SearchCommanderAI.o ../BZRFlag\ AI/SearchCommanderAI.cpp

${OBJECTDIR}/_ext/693638321/ShooterCommanderAI.o: ../BZRFlag\ AI/ShooterCommanderAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/ShooterCommanderAI.o ../BZRFlag\ AI/ShooterCommanderAI.cpp

${OBJECTDIR}/_ext/693638321/PotentialFieldTankAI.o: ../BZRFlag\ AI/PotentialFieldTankAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/PotentialFieldTankAI.o ../BZRFlag\ AI/PotentialFieldTankAI.cpp

${OBJECTDIR}/_ext/693638321/StraightLineCommanderAI.o: ../BZRFlag\ AI/StraightLineCommanderAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/StraightLineCommanderAI.o ../BZRFlag\ AI/StraightLineCommanderAI.cpp

${OBJECTDIR}/_ext/693638321/DumbTankAI.o: ../BZRFlag\ AI/DumbTankAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/DumbTankAI.o ../BZRFlag\ AI/DumbTankAI.cpp

${OBJECTDIR}/_ext/693638321/IDArraySearcher.o: ../BZRFlag\ AI/IDArraySearcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/IDArraySearcher.o ../BZRFlag\ AI/IDArraySearcher.cpp

${OBJECTDIR}/_ext/693638321/DepthLimitedArraySearcher.o: ../BZRFlag\ AI/DepthLimitedArraySearcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/DepthLimitedArraySearcher.o ../BZRFlag\ AI/DepthLimitedArraySearcher.cpp

${OBJECTDIR}/_ext/693638321/SearchTools.o: ../BZRFlag\ AI/SearchTools.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/SearchTools.o ../BZRFlag\ AI/SearchTools.cpp

${OBJECTDIR}/_ext/693638321/TankTargeter.o: ../BZRFlag\ AI/TankTargeter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/TankTargeter.o ../BZRFlag\ AI/TankTargeter.cpp

${OBJECTDIR}/_ext/693638321/TankVector.o: ../BZRFlag\ AI/TankVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/TankVector.o ../BZRFlag\ AI/TankVector.cpp

${OBJECTDIR}/_ext/693638321/BZRCTools.o: ../BZRFlag\ AI/BZRCTools.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/693638321
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/693638321/BZRCTools.o ../BZRFlag\ AI/BZRCTools.cpp

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
