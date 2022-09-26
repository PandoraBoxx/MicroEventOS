#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PwmSignal05Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PwmSignal05Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=machine/adcv_machine.c machine/event_process.c machine/msim_machine.c machine/servo_process.c machine/timer_machine.c machine/uart_machine.c peripheral/adcv_config.c peripheral/gpio_config.c peripheral/msim_config.c peripheral/pwm_config.c peripheral/qeim_config.c peripheral/timer_config.c peripheral/uart_config.c system/system_config.c system/system_init.c system/system_interrupt.c system/system_traps.c main.c /home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}/PwmSignal05Slave.s 

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/machine/adcv_machine.o ${OBJECTDIR}/machine/event_process.o ${OBJECTDIR}/machine/msim_machine.o ${OBJECTDIR}/machine/servo_process.o ${OBJECTDIR}/machine/timer_machine.o ${OBJECTDIR}/machine/uart_machine.o ${OBJECTDIR}/peripheral/adcv_config.o ${OBJECTDIR}/peripheral/gpio_config.o ${OBJECTDIR}/peripheral/msim_config.o ${OBJECTDIR}/peripheral/pwm_config.o ${OBJECTDIR}/peripheral/qeim_config.o ${OBJECTDIR}/peripheral/timer_config.o ${OBJECTDIR}/peripheral/uart_config.o ${OBJECTDIR}/system/system_config.o ${OBJECTDIR}/system/system_init.o ${OBJECTDIR}/system/system_interrupt.o ${OBJECTDIR}/system/system_traps.o ${OBJECTDIR}/main.o ${OBJECTDIR}/PwmSignal05Slave.o 
POSSIBLE_DEPFILES=${OBJECTDIR}/machine/adcv_machine.o.d ${OBJECTDIR}/machine/event_process.o.d ${OBJECTDIR}/machine/msim_machine.o.d ${OBJECTDIR}/machine/servo_process.o.d ${OBJECTDIR}/machine/timer_machine.o.d ${OBJECTDIR}/machine/uart_machine.o.d ${OBJECTDIR}/peripheral/adcv_config.o.d ${OBJECTDIR}/peripheral/gpio_config.o.d ${OBJECTDIR}/peripheral/msim_config.o.d ${OBJECTDIR}/peripheral/pwm_config.o.d ${OBJECTDIR}/peripheral/qeim_config.o.d ${OBJECTDIR}/peripheral/timer_config.o.d ${OBJECTDIR}/peripheral/uart_config.o.d ${OBJECTDIR}/system/system_config.o.d ${OBJECTDIR}/system/system_init.o.d ${OBJECTDIR}/system/system_interrupt.o.d ${OBJECTDIR}/system/system_traps.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/machine/adcv_machine.o ${OBJECTDIR}/machine/event_process.o ${OBJECTDIR}/machine/msim_machine.o ${OBJECTDIR}/machine/servo_process.o ${OBJECTDIR}/machine/timer_machine.o ${OBJECTDIR}/machine/uart_machine.o ${OBJECTDIR}/peripheral/adcv_config.o ${OBJECTDIR}/peripheral/gpio_config.o ${OBJECTDIR}/peripheral/msim_config.o ${OBJECTDIR}/peripheral/pwm_config.o ${OBJECTDIR}/peripheral/qeim_config.o ${OBJECTDIR}/peripheral/timer_config.o ${OBJECTDIR}/peripheral/uart_config.o ${OBJECTDIR}/system/system_config.o ${OBJECTDIR}/system/system_init.o ${OBJECTDIR}/system/system_interrupt.o ${OBJECTDIR}/system/system_traps.o ${OBJECTDIR}/main.o ${OBJECTDIR}/PwmSignal05Slave.o 

# Source Files
SOURCEFILES=machine/adcv_machine.c machine/event_process.c machine/msim_machine.c machine/servo_process.c machine/timer_machine.c machine/uart_machine.c peripheral/adcv_config.c peripheral/gpio_config.c peripheral/msim_config.c peripheral/pwm_config.c peripheral/qeim_config.c peripheral/timer_config.c peripheral/uart_config.c system/system_config.c system/system_init.c system/system_interrupt.c system/system_traps.c main.c /home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}/PwmSignal05Slave.s 



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PwmSignal05Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CH64MP202
MP_LINKER_FILE_OPTION=,--script=p33CH64MP202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/machine/adcv_machine.o: machine/adcv_machine.c  .generated_files/flags/default/83b8967680183f8ec4340bf8c5e4a181fbfb9800 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/adcv_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/adcv_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/adcv_machine.c  -o ${OBJECTDIR}/machine/adcv_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/adcv_machine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/event_process.o: machine/event_process.c  .generated_files/flags/default/7b4b55ed52d1b182569e7926167bb118b1a58128 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/event_process.o.d 
	@${RM} ${OBJECTDIR}/machine/event_process.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/event_process.c  -o ${OBJECTDIR}/machine/event_process.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/event_process.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/msim_machine.o: machine/msim_machine.c  .generated_files/flags/default/d25d538510f35dd9961389536a3fefa58a463bdd .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/msim_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/msim_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/msim_machine.c  -o ${OBJECTDIR}/machine/msim_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/msim_machine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/servo_process.o: machine/servo_process.c  .generated_files/flags/default/1ce6f86b84b070fab7635090a992724133a92a1c .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/servo_process.o.d 
	@${RM} ${OBJECTDIR}/machine/servo_process.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/servo_process.c  -o ${OBJECTDIR}/machine/servo_process.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/servo_process.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/timer_machine.o: machine/timer_machine.c  .generated_files/flags/default/35520fcbe7baa3eacbd1605ee0e5bad22000314e .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/timer_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/timer_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/timer_machine.c  -o ${OBJECTDIR}/machine/timer_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/timer_machine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/uart_machine.o: machine/uart_machine.c  .generated_files/flags/default/d8900db97a1681fa3d06ea72c4a80292acc83c46 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/uart_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/uart_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/uart_machine.c  -o ${OBJECTDIR}/machine/uart_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/uart_machine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/adcv_config.o: peripheral/adcv_config.c  .generated_files/flags/default/bc908402667bd6cb9359c051e9334a4ea0433a10 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/adcv_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/adcv_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/adcv_config.c  -o ${OBJECTDIR}/peripheral/adcv_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/adcv_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/gpio_config.o: peripheral/gpio_config.c  .generated_files/flags/default/a3bdf118e87a3ff4f3e9a25f5cfe3549c9c921d7 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/gpio_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/gpio_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/gpio_config.c  -o ${OBJECTDIR}/peripheral/gpio_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/gpio_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/msim_config.o: peripheral/msim_config.c  .generated_files/flags/default/bb2993e887b85f85c06b15f8aee6ea92162a4d75 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/msim_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/msim_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/msim_config.c  -o ${OBJECTDIR}/peripheral/msim_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/msim_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/pwm_config.o: peripheral/pwm_config.c  .generated_files/flags/default/de954315a44ef44b11648d65e71084618e847f7b .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/pwm_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/pwm_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/pwm_config.c  -o ${OBJECTDIR}/peripheral/pwm_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/pwm_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/qeim_config.o: peripheral/qeim_config.c  .generated_files/flags/default/f97e3fa2dbd5d09501a8381983021d508e618bcd .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/qeim_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/qeim_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/qeim_config.c  -o ${OBJECTDIR}/peripheral/qeim_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/qeim_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/timer_config.o: peripheral/timer_config.c  .generated_files/flags/default/85a5c6725ebb7f59a63880690948022d0deba9ec .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/timer_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/timer_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/timer_config.c  -o ${OBJECTDIR}/peripheral/timer_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/timer_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/uart_config.o: peripheral/uart_config.c  .generated_files/flags/default/f717df92d85607d6c3f8465f73e713f34ad5d4d0 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/uart_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/uart_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/uart_config.c  -o ${OBJECTDIR}/peripheral/uart_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/uart_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_config.o: system/system_config.c  .generated_files/flags/default/f5c15edaa196c7d88b392ea74e465cb503b6a4f8 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_config.o.d 
	@${RM} ${OBJECTDIR}/system/system_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_config.c  -o ${OBJECTDIR}/system/system_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_init.o: system/system_init.c  .generated_files/flags/default/ef22b20ecc233865ff16927165ad368d29e38a74 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_init.o.d 
	@${RM} ${OBJECTDIR}/system/system_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_init.c  -o ${OBJECTDIR}/system/system_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_init.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_interrupt.o: system/system_interrupt.c  .generated_files/flags/default/ee80b6432c38163e78fe055f093c1359e5edcae8 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/system/system_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_interrupt.c  -o ${OBJECTDIR}/system/system_interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_traps.o: system/system_traps.c  .generated_files/flags/default/e0002befebe95fb7854deb059a7ccc08f03c01e7 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_traps.o.d 
	@${RM} ${OBJECTDIR}/system/system_traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_traps.c  -o ${OBJECTDIR}/system/system_traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/d49ee223f48d4dbdc04b5e475ba01305b8ebe73 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
else
${OBJECTDIR}/machine/adcv_machine.o: machine/adcv_machine.c  .generated_files/flags/default/3433654b65b5811fd5bc879ba93c1a3c8bc335ba .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/adcv_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/adcv_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/adcv_machine.c  -o ${OBJECTDIR}/machine/adcv_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/adcv_machine.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/event_process.o: machine/event_process.c  .generated_files/flags/default/10fefe8ba61dc0c3326aa8803e319b6ef89c14fa .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/event_process.o.d 
	@${RM} ${OBJECTDIR}/machine/event_process.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/event_process.c  -o ${OBJECTDIR}/machine/event_process.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/event_process.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/msim_machine.o: machine/msim_machine.c  .generated_files/flags/default/23d0320cac6b34dc7da5088011b37f53c560e09b .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/msim_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/msim_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/msim_machine.c  -o ${OBJECTDIR}/machine/msim_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/msim_machine.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/servo_process.o: machine/servo_process.c  .generated_files/flags/default/64d9780e769bb8614c8872d1959e9063caee95d6 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/servo_process.o.d 
	@${RM} ${OBJECTDIR}/machine/servo_process.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/servo_process.c  -o ${OBJECTDIR}/machine/servo_process.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/servo_process.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/timer_machine.o: machine/timer_machine.c  .generated_files/flags/default/6f69228b522f72c19c0fdf91fe034ddd169cff43 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/timer_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/timer_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/timer_machine.c  -o ${OBJECTDIR}/machine/timer_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/timer_machine.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/machine/uart_machine.o: machine/uart_machine.c  .generated_files/flags/default/5429f5902dfa3429e780d482d8bbc963ac556dc3 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/machine" 
	@${RM} ${OBJECTDIR}/machine/uart_machine.o.d 
	@${RM} ${OBJECTDIR}/machine/uart_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  machine/uart_machine.c  -o ${OBJECTDIR}/machine/uart_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/machine/uart_machine.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/adcv_config.o: peripheral/adcv_config.c  .generated_files/flags/default/71801b7c5d7a925427ac9dd169a02536145b17bf .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/adcv_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/adcv_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/adcv_config.c  -o ${OBJECTDIR}/peripheral/adcv_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/adcv_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/gpio_config.o: peripheral/gpio_config.c  .generated_files/flags/default/220e6c9b8d5708c17879edf563b6c0877de19a77 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/gpio_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/gpio_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/gpio_config.c  -o ${OBJECTDIR}/peripheral/gpio_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/gpio_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/msim_config.o: peripheral/msim_config.c  .generated_files/flags/default/8477c0e19409d02be8f08b5f7b02aecf8f408974 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/msim_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/msim_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/msim_config.c  -o ${OBJECTDIR}/peripheral/msim_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/msim_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/pwm_config.o: peripheral/pwm_config.c  .generated_files/flags/default/bb9e0da37ce2cc43e3055293bbe777e397be72 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/pwm_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/pwm_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/pwm_config.c  -o ${OBJECTDIR}/peripheral/pwm_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/pwm_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/qeim_config.o: peripheral/qeim_config.c  .generated_files/flags/default/32508759a541363397c7c6959a8963c6f96aeacd .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/qeim_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/qeim_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/qeim_config.c  -o ${OBJECTDIR}/peripheral/qeim_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/qeim_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/timer_config.o: peripheral/timer_config.c  .generated_files/flags/default/11f3b0a572e02426cb2a5cd9cc1c498f6ae466f8 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/timer_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/timer_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/timer_config.c  -o ${OBJECTDIR}/peripheral/timer_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/timer_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/peripheral/uart_config.o: peripheral/uart_config.c  .generated_files/flags/default/23a57e34bf2ee783f4fc8667aab4e0241a035c .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/peripheral" 
	@${RM} ${OBJECTDIR}/peripheral/uart_config.o.d 
	@${RM} ${OBJECTDIR}/peripheral/uart_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  peripheral/uart_config.c  -o ${OBJECTDIR}/peripheral/uart_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/peripheral/uart_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_config.o: system/system_config.c  .generated_files/flags/default/4363ff17d6b0f6fe07fbf98beb180ee52c90a612 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_config.o.d 
	@${RM} ${OBJECTDIR}/system/system_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_config.c  -o ${OBJECTDIR}/system/system_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_config.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_init.o: system/system_init.c  .generated_files/flags/default/b43fa5fb7e403618be1025dc04e49dc2cdec845b .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_init.o.d 
	@${RM} ${OBJECTDIR}/system/system_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_init.c  -o ${OBJECTDIR}/system/system_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_init.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_interrupt.o: system/system_interrupt.c  .generated_files/flags/default/e15a43d517619e41381064770dca08506afd2c56 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/system/system_interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_interrupt.c  -o ${OBJECTDIR}/system/system_interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_interrupt.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/system/system_traps.o: system/system_traps.c  .generated_files/flags/default/700e61cf6a958242e37d8c96e68b97f1fe4a6580 .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}/system" 
	@${RM} ${OBJECTDIR}/system/system_traps.o.d 
	@${RM} ${OBJECTDIR}/system/system_traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system/system_traps.c  -o ${OBJECTDIR}/system/system_traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system/system_traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/53880c7b64e67c57c569f01ac25f27f263aca1ac .generated_files/flags/default/4d09e4fae09f7d4b258b2ca9fad74aad68fb5efa
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble_subordinate
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/PwmSignal05Slave.o: /home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}/PwmSignal05Slave.s  nbproject/Makefile-${CND_CONF}.mk
	${MP_CC} -c -mcpu=$(MP_PROCESSOR_OPTION)    /home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}/PwmSignal05Slave.s  -o ${OBJECTDIR}/PwmSignal05Slave.o
else
${OBJECTDIR}/PwmSignal05Slave.o: /home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}/PwmSignal05Slave.s  nbproject/Makefile-${CND_CONF}.mk
	${MP_CC} -c -mcpu=$(MP_PROCESSOR_OPTION)    /home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}/PwmSignal05Slave.s  -o ${OBJECTDIR}/PwmSignal05Slave.o
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PwmSignal05Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PwmSignal05Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
${DISTDIR}/PwmSignal05Master.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PwmSignal05Master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -I"/home/alejito/MPLABXProjects/PwmSignal05Slave.X/dist/default/${IMAGE_TYPE}"  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}/xc16-bin2hex ${DISTDIR}/PwmSignal05Master.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
endif


# Subprojects
.build-subprojects:
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
	cd ../PwmSignal05Slave.X && ${MAKE}  -f Makefile CONF=default TYPE_IMAGE=DEBUG_RUN
	cd ../PwmSignal05Slave.X && ${MAKE}  -f Makefile CONF=default TYPE_IMAGE=DEBUG_RUN SUB_IMAGE_NAME=PwmSignal05Slave .build-sub-images-impl
else
	cd ../PwmSignal05Slave.X && ${MAKE}  -f Makefile CONF=default
	cd ../PwmSignal05Slave.X && ${MAKE}  -f Makefile CONF=default SUB_IMAGE_NAME=PwmSignal05Slave .build-sub-images-impl
endif


# Subprojects
.clean-subprojects:
	cd ../PwmSignal05Slave.X && rm -rf "build/default" "dist/default"

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
