/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015, 2018 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_cgc.h
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for CGC module.
* Creation Date: 07-06-2023
***********************************************************************************************************************/
#ifndef CGC_H
#define CGC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    MainOSC Enable Register (MOSCE)
*/
/* MainOSC disable trigger (MOSCDISTRG) */
#define _CGC_MAINOSC_STOP                         (0x00000002UL) /* Stops MainOSC */
/* MainOSC enable trigger (MOSCENTRG) */
#define _CGC_MAINOSC_START                        (0x00000001UL) /* Starts MainOSC */

/*
    MainOSC Status Register (MOSCS)
*/
/* MainOSC active status (MOSCCLKACT) */
#define _CGC_MAINOSC_ACTIVE                       (0x00000004UL) /* MainOSC is active */

/*
    MainOSC Control Register (MOSCC)
*/
/* MainOSC frequency selection (MOSCAMPSEL1,MOSCAMPSEL0) */
#define _CGC_MAINOSC_24MHZ                        (0x00000000UL) /* 24MHz */
#define _CGC_MAINOSC_20MHZ                        (0x00000001UL) /* 20MHz */
#define _CGC_MAINOSC_16MHZ                        (0x00000002UL) /* 16MHz */

/*
    MainOSC Stop Mask Register (MOSCSTPM)
*/
/* MainOSC stop request mask (MOSCSTPMSK) */
#define _CGC_MAINOSC_REQUEST_STOP                 (0x00000000UL) /* MainOSC stops operation in standby mode */
#define _CGC_MAINOSC_REQUEST_CONTINUE             (0x00000001UL) /* MainOSC continues operation in standby mode */

/*
    MainOSC Mode Control Register (MOSCM)
*/
/* MainOSC mode control (MOSCM) */
#define _CGC_MAINOSC_OSC_MODE                     (0x00000000UL) /* OSC mode */
#define _CGC_MAINOSC_EXCLK_MODE                   (0x00000001UL) /* EXCLK mode */

/*
    SubOSC Enable Register (SOSCE)
*/
/* SubOSC disable trigger (SOSCDISTRG) */
#define _CGC_SUBOSC_STOP                          (0x00000002UL) /* Stops SubOSC */
/* SubOSC enable trigger (SOSCENTRG) */
#define _CGC_SUBOSC_START                         (0x00000001UL) /* Starts SubOSC */

/*
    SubOSC Status Register (SOSCS)
*/
/* SubOSC activation status (SOSCCLKACT) */
#define _CGC_SUBOSC_ACTIVE                        (0x00000004UL) /* SubOSC is active */

/*
    HS IntOSC Enable Register (ROSCE)
*/
/* HS IntOSC disable trigger (ROSCDISTRG) */
#define _CGC_HSOSC_STOP                           (0x00000002UL) /* Stops HS IntOSC */

/*
    HS IntOSC Status Register (ROSCS)
*/
/* HS IntOSC active status (ROSCCLKACT) */
#define _CGC_HSOSC_ACTIVE                         (0x00000004UL) /* HS IntOSC is active */
#define _CGC_HSOSC_INACTIVE                       (0x00000000UL) /* HS IntOSC is inactive */

/*
    HS IntOSC Stop Mask Register (ROSCSTPM)
*/
/* HS IntOSC Stop Request Mask (ROSCSTPMSK) */
#define _CGC_HSOSC_REQUEST_STOP                   (0x00000000UL) /* HS IntOSC stops operation in standby mode */
#define _CGC_HSOSC_REQUEST_CONTINUE               (0x00000001UL) /* HS IntOSC continues operation in standby mode */

/*
    PLL Enable Register (PLLE)
*/
/* PLL disable trigger (PLLDISTRG) */
#define _CGC_PLL_STOP                             (0x00000002UL) /* Stops PLL */
/* PLL Enable Trigger (PLLENTRG) */
#define _CGC_PLL_START                            (0x00000001UL) /* Starts PLL */

/*
    PLL Status Register (PLLS)
*/
/* PLL active status (PLLCLKACT) */
#define _CGC_PLL_ACTIVE                           (0x00000004UL) /* PLL is active */

/*
    PLL Input Clock Selection Register (CKSC_PLLIS_CTL)
*/
/* Source clock setting for PLL input clock (PLLISCSID1,PLLISCSID0) */
#define _CGC_PLL_SOURCE_MAINOSC                   (0x00000001UL) /* Main OSC */
#define _CGC_PLL_SOURCE_HSOSC                     (0x00000002UL) /* HS IntOSC */

/*
    PLL Input Clock Active Register (CKSC_PLLIS_ACT)
*/
/* Source clock for currently active PLL input clock (PLLISACT1,PLLISACT0) */
#define _CGC_PLL_SOURCE_ACTIVE                    (0x00000003UL) /* Source clock for currently active PLL input clock */

/*
    PPLLCLK Source Clock Selection Register (CKSC_PPLLCLKS_CTL)
*/
/* Source clock setting for PPLLCLK (PPLLCLKSCSID1,PPLLCLKSCSID0) */
#define _CGC_PPLLCLK_SOURCE_DISABLE               (0x00000000UL) /* Disabled */
#define _CGC_PPLLCLK_SOURCE_EMCLK                 (0x00000001UL) /* Emergency clock EMCLK */
#define _CGC_PPLLCLK_SOURCE_MAINOSC               (0x00000002UL) /* MainOSC */
#define _CGC_PPLLCLK_SOURCE_PPLLOUT               (0x00000003UL) /* PPLLOUT */

/*
    PPLLCLK Source Clock Active Register (CKSC_PPLLCLKS_ACT)
*/
/* Source clock for currently active PPLLCLK (PPLLCLKSCSID1,PPLLCLKSCSID0) */
#define _CGC_PPLLCLK_SOURCE_ACTIVE                (0x00000003UL) /* Source clock for currently active PPLLCLK */

/*
    C_AWO_WDTA Clock Divider Selection Register (CKSC_AWDTAD_CTL)
*/
/* Clock Divider Setting for C_AWO_WDTA (AWDTADCSID1,AWDTADCSID0) */
#define _CGC_WDTA_CLK_SOURCE_LSOSC_128            (0x00000001UL) /* LS IntOSC / 128 (default) */
#define _CGC_WDTA_CLK_SOURCE_LSOSC_1              (0x00000002UL) /* LS IntOSC / 1 */

/*
    C_AWO_WDTA Stop Mask Register (CKSC_AWDTAD_STPM)
*/
/* C_AWO_WDTA Stop Request Mask (AWDTADSTPMSK) */
#define _CGC_WDTA_CLK_REQUEST_STOP                (0x00000000UL) /* C_AWO_WDTA is stopped in standby mode */
#define _CGC_WDTA_CLK_REQUEST_CONTINUE            (0x00000001UL) /* C_AWO_WDTA is not stopped in standby mode */

/*
    C_AWO_TAUJ Source Clock Selection Register (CKSC_ATAUJS_CTL)
*/
/* Source clock setting for C_AWO_TAUJ (ATAUJSCSID2,ATAUJSCSID1,ATAUJSCSID0) */
#define _CGC_TAUJ_CLK_SOURCE_DISABLE              (0x00000000UL) /* Disabled */
#define _CGC_TAUJ_CLK_SOURCE_HSOSC                (0x00000001UL) /* HS IntOSC (default) */
#define _CGC_TAUJ_CLK_SOURCE_MAINOSC              (0x00000002UL) /* MainOSC */
#define _CGC_TAUJ_CLK_SOURCE_LSOSC                (0x00000003UL) /* LS IntOSC */
#define _CGC_TAUJ_CLK_SOURCE_PPLLCLK2             (0x00000004UL) /* PPLLCLK2 */

/*
    C_AWO_TAUJ Clock Divider Selection Register (CKSC_ATAUJD_CTL)
*/
/* Clock Divider Setting for C_AWO_TAUJ (ATAUJDCSID2,ATAUJDCSID1,ATAUJDCSID0) */
#define _CGC_TAUJ_CLK_DIVIDER_1                   (0x00000001UL) /* CKSC_ATAUJS_CTL selection /1 (default) */
#define _CGC_TAUJ_CLK_DIVIDER_2                   (0x00000002UL) /* CKSC_ATAUJS_CTL selection /2 */
#define _CGC_TAUJ_CLK_DIVIDER_4                   (0x00000003UL) /* CKSC_ATAUJS_CTL selection /4 */
#define _CGC_TAUJ_CLK_DIVIDER_8                   (0x00000004UL) /* CKSC_ATAUJS_CTL selection /8 */

/*
    C_AWO_WDTA Stop Mask Register (CKSC_ATAUJD_STPM)
*/
/* C_AWO_TAUJ Stop Request Mask (ATAUJDSTPMSK) */
#define _CGC_TAUJ_CLK_REQUEST_STOP                (0x00000000UL) /* C_AWO_TAUJ is stopped in standby mode */
#define _CGC_TAUJ_CLK_REQUEST_CONTINUE            (0x00000001UL) /* C_AWO_TAUJ is not stopped in standby mode */

/*
    C_AWO_RTCA Source Clock Selection Register (CKSC_ARTCAS_CTL)
*/
/* Source clock setting for C_AWO_RTCA (ARTCASCSID1,ARTCASCSID0) */
#define _CGC_RTCA_CLK_SOURCE_DISABLE              (0x00000000UL) /* Disabled(default) */
#define _CGC_RTCA_CLK_SOURCE_SUBOSC               (0x00000001UL) /* SubOSC */
#define _CGC_RTCA_CLK_SOURCE_MAINOSC              (0x00000002UL) /* MainOSC */
#define _CGC_RTCA_CLK_SOURCE_LSOSC                (0x00000003UL) /* LS IntOSC */

/*
    C_AWO_RTCA Clock Divider Register (CKSC_ARTCAD_CTL)
*/
/* Clock divider setting for C_AWO_RTCA (ARTCADCSID2,ARTCADCSID1,ARTCADCSID0) */
#define _CGC_RTCA_CLK_DIVIDER_DISABLE             (0x00000000UL) /* Disabled (default) */
#define _CGC_RTCA_CLK_DIVIDER_1                   (0x00000001UL) /* CKSC_ARTCAS_CTL selection /1 */
#define _CGC_RTCA_CLK_DIVIDER_2                   (0x00000002UL) /* CKSC_ARTCAS_CTL selection /2 */
#define _CGC_RTCA_CLK_DIVIDER_4                   (0x00000003UL) /* CKSC_ARTCAS_CTL selection /4 */
#define _CGC_RTCA_CLK_DIVIDER_8                   (0x00000004UL) /* CKSC_ARTCAS_CTL selection /8 */

/*
    C_AWO_RTCA Stop Mask Register (CKSC_ARTCAD_STPM)
*/
/* C_AWO_RTCA stop request mask (ARTCADSTPMSK) */
#define _CGC_RTCA_CLK_REQUEST_STOP                (0x00000000UL) /* C_AWO_RTCA is stopped in standby mode */
#define _CGC_RTCA_CLK_REQUEST_CONTINUE            (0x00000001UL) /* C_AWO_RTCA is not stopped in standby mode */

/*
    C_AWO_ADCA Source Clock Selection Register (CKSC_AADCAS_CTL)
*/
/* Source clock setting for C_AWO_ADCA (AADCASCSID1,AADCASCSID0) */
#define _CGC_ADCA0_CLK_SOURCE_DISABLE             (0x00000000UL) /* Disabled */
#define _CGC_ADCA0_CLK_SOURCE_HSOSC               (0x00000001UL) /* HS IntOSC (default) */
#define _CGC_ADCA0_CLK_SOURCE_MAINOSC             (0x00000002UL) /* MainOSC */
#define _CGC_ADCA0_CLK_SOURCE_PPLLCLK2            (0x00000003UL) /* PPLLCLK2 */

/*
    C_AWO_RTCA Clock Divider Register (CKSC_AADCAD_CTL)
*/
/* Clock divider setting for C_AWO_ADCA (AADCADCSID1,AADCADCSID0) */
#define _CGC_ADCA0_CLK_DIVIDER_1                  (0x00000001UL) /* CKSC_AADCAS_CTL selection /1 (default) */
#define _CGC_ADCA0_CLK_DIVIDER_2                  (0x00000002UL) /* CKSC_AADCAS_CTL selection /2 */

/*
    C_AWO_ADCA Stop Mask Register (CKSC_AADCAD_STPM)
*/
/* C_AWO_ADCA stop request mask (AADCADSTPMSK) */
#define _CGC_ADCA0_CLK_REQUEST_STOP               (0x00000000UL) /* C_AWO_RTCA is stopped in standby mode */
#define _CGC_ADCA0_CLK_REQUEST_CONTINUE           (0x00000001UL) /* C_AWO_RTCA is not stopped in standby mode */

/*
    C_AWO_FOUT Source Clock Selection Register (CKSC_AFOUTS_CTL)
*/
/* Source clock setting for C_AWO_FOUT (AFOUTSCSID2,AFOUTSCSID1,AFOUTSCSID0) */
#define _CGC_FOUT_CLK_SOURCE_DISABLE              (0x00000000UL) /* Disabled (default) */
#define _CGC_FOUT_CLK_SOURCE_MAINOSC              (0x00000001UL) /* MainOSC */
#define _CGC_FOUT_CLK_SOURCE_HSOSC                (0x00000002UL) /* HS IntOSC */
#define _CGC_FOUT_CLK_SOURCE_LSOSC                (0x00000003UL) /* LS IntOSC */
#define _CGC_FOUT_CLK_SOURCE_SUBOSC               (0x00000004UL) /* SubOSC */
#define _CGC_FOUT_CLK_SOURCE_PPLLCLK4             (0x00000005UL) /* PPLLCLK4 */

/*
    C_AWO_FOUT Stop Mask Register (CKSC_AFOUTS_STPM)
*/
/* C_AWO_FOUT stop request mask (AFOUTSSTPMSK) */
#define _CGC_FOUT_CLK_REQUEST_STOP                (0x00000000UL) /* C_AWO_FOUT is stopped in standby mode */
#define _CGC_FOUT_CLK_REQUEST_CONTINUE            (0x00000001UL) /* C_AWO_FOUT is not stopped in standby mode */

/*
    C_ISO_CPUCLK Source Clock Selection Register (CKSC_CPUCLKS_CTL)
*/
/* Source clock setting for C_ISO_CPUCLK (CPUCLKSCSID1,CPUCLKSCSID0) */
#define _CGC_CPU_CLK_SOURCE_EMCLK                 (0x00000001UL) /* EMCLK (default) */
#define _CGC_CPU_CLK_SOURCE_MAINOSC               (0x00000002UL) /* MainOSC */
#define _CGC_CPU_CLK_SOURCE_CPLLOUT               (0x00000003UL) /* CPLLOUT */

/*
    C_ISO_CPUCLK Clock Divider Selection Register (CKSC_CPUCLKD_CTL)
*/
/* Clock divider CPLLDIV setting (CPUCLKDPLL1,CPUCLKDPLL0) */
#define _CGC_CPLLOUT_DIVIDER_6                    (0x00000000UL) /* CPLLOUT = VCOOUT * 1/6 (80 MHz) */
#define _CGC_CPLLOUT_DIVIDER_5                    (0x00000008UL) /* CPLLOUT = VCOOUT * 1/5 (96 MHz) */
#define _CGC_CPLLOUT_DIVIDER_4                    (0x00000010UL) /* CPLLOUT = VCOOUT * 1/4 (120 MHz) */
/* Clock divider setting for C_ISO_CPUCLK (CPUCLKDCSID2,CPUCLKDCSID1,CPUCLKDCSID0) */
#define _CGC_CPU_CLK_DIVIDER_1                    (0x00000001UL) /* CKSC_CPUCLKS_CTL selection /1 (Default) */
#define _CGC_CPU_CLK_DIVIDER_2                    (0x00000002UL) /* CKSC_CPUCLKS_CTL selection /2 */
#define _CGC_CPU_CLK_DIVIDER_4                    (0x00000003UL) /* CKSC_CPUCLKS_CTL selection /4 */
#define _CGC_CPU_CLK_DIVIDER_8                    (0x00000004UL) /* CKSC_CPUCLKS_CTL selection /8 */

/*
    C_ISO_PERI1 Source Clock Selection Register (CKSC_IPERI1S_CTL)
*/
/* Source clock setting for C_ISO_PERI1 (IPERI1SCSID1,IPERI1SCSID0) */
#define _CGC_PERI1_CLK_SOURCE_DISABLE             (0x00000000UL) /* Disabled */
#define _CGC_PERI1_CLK_SOURCE_PPLLCLK             (0x00000001UL) /* PPLLCLK (default) */

/*
    C_ISO_PERI2 Source Clock Selection Register (CKSC_IPERI2S_CTL)
*/
/* Source clock setting for C_ISO_PERI2 (IPERI2SCSID1,IPERI2SCSID0) */
#define _CGC_PERI2_CLK_SOURCE_DISABLE             (0x00000000UL) /* Disabled */
#define _CGC_PERI2_CLK_SOURCE_PPLLCLK2            (0x00000001UL) /* PPLLCLK2 (default) */

/*
    C_ISO_LIN Source Clock Selection Register (CKSC_ILINS_CTL)
*/
/* Source clock setting for C_ISO_LIN (ILINSCSID2,ILINSCSID1,ILINSCSID0) */
#define _CGC_RLIN_CLK_SOURCE_DISABLE              (0x00000000UL) /* Disabled */
#define _CGC_RLIN_CLK_SOURCE_PPLLCLK2             (0x00000001UL) /* PPLLCLK2 (default) */
#define _CGC_RLIN_CLK_SOURCE_MAINOSC              (0x00000002UL) /* MainOSC */
#define _CGC_RLIN_CLK_SOURCE_HSOSC                (0x00000004UL) /* HS IntOSC */

/*
    C_ISO_LIN Clock Divider Selection Register (CKSC_ILIND_CTL)
*/
/* Clock divider setting for C_ISO_LIN (ILINDCSID1,ILINDCSID0) */
#define _CGC_RLIN_CLK_DIVIDER_1                   (0x00000001UL) /* CKSC_ILINS_CTL selection /1 (default) */
#define _CGC_RLIN_CLK_DIVIDER_4                   (0x00000002UL) /* CKSC_ILINS_CTL selection /4 */
#define _CGC_RLIN_CLK_DIVIDER_8                   (0x00000003UL) /* CKSC_ILINS_CTL selection /8 */

/*
    C_ISO_LIN Stop Mask Register (CKSC_ILIND_STPM)
*/
/* C_AWO_FOUT stop request mask (ILINDSTPMSK) */
#define _CGC_RLIN_CLK_REQUEST_STOP                (0x00000000UL) /* C_ISO_LIN is stopped in standby mode */
#define _CGC_RLIN_CLK_REQUEST_CONTINUE            (0x00000001UL) /* C_ISO_LIN is not stopped in standby mode */

/*
    C_ISO_ADCA Source Clock Selection Register (CKSC_IADCAS_CTL)
*/
/* Source clock setting for C_ISO_ADCA (IADCASCSID1,IADCASCSID0) */
#define _CGC_ADCA1_CLK_SOURCE_DISABLE             (0x00000000UL) /* Disabled */
#define _CGC_ADCA1_CLK_SOURCE_HSOSC               (0x00000001UL) /* HS IntOSC (default) */
#define _CGC_ADCA1_CLK_SOURCE_MAINOSC             (0x00000002UL) /* MainOSC */
#define _CGC_ADCA1_CLK_SOURCE_PPLLCLK2            (0x00000003UL) /* PPLLCLK2 */

/*
    C_ISO_ADCA Clock Divider Selection Register (CKSC_IADCAD_CTL)
*/
/* Clock divider setting for C_ISO_ADCA (IADCADCSID1,IADCADCSID0) */
#define _CGC_ADCA1_CLK_DIVIDER_1                  (0x00000001UL) /* CKSC_IADCAS_CTL selection /1 (default) */
#define _CGC_ADCA1_CLK_DIVIDER_2                  (0x00000002UL) /* CKSC_IADCAS_CTL selection /2 */

/*
    C_ISO_CAN Source Clock Selection Register (CKSC_ICANS_CTL)
*/
/* Source clock setting for C_ISO_CAN (ICANSCSID1,ICANSCSID0) */
#define _CGC_RSCAN_CLK_SOURCE_DISABLE             (0x00000000UL) /* Disabled */
#define _CGC_RSCAN_CLK_SOURCE_MAINOSC             (0x00000001UL) /* MainOSC */
#define _CGC_RSCAN_CLK_SOURCE_PPLLCLK             (0x00000003UL) /* PPLLCLK (default) */

/*
    C_ISO_CAN Stop Mask Register (CKSC_ICANS_STPM)
*/
/* C_ISO_CAN stop request mask (ICANSSTPMSK) */
#define _CGC_RSCAN_CLK_REQUEST_STOP               (0x00000000UL) /* C_ISO_CAN is stopped in standby mode */
#define _CGC_RSCAN_CLK_REQUEST_CONTINUE           (0x00000001UL) /* C_ISO_CAN is not stopped in standby mode */

/*
    C_ISO_CANOSC Clock Divider Selection Register (CKSC_ICANOSCD_CTL)
*/
/* Clock divider setting for C_ISO_CANOSC (ICANOSCDCSID1,ICANOSCDCSID0) */
#define _CGC_RSCANOSC_CLK_SOURCE_DISABLE          (0x00000000UL) /* Disabled(default) */
#define _CGC_RSCANOSC_CLK_SOURCE_MAINOSC          (0x00000001UL) /* MainOSC/1 */
#define _CGC_RSCANOSC_CLK_SOURCE_MAINOSC2         (0x00000002UL) /* MainOSC/2 */

/*
    C_ISO_CANOSC Stop Mask Register (CKSC_ICANOSCD_STPM)
*/
/* C_ISO_CANOSC stop request mask (ICANOSCDSTPMSK) */
#define _CGC_RSCANOSC_CLK_REQUEST_STOP            (0x00000000UL) /* C_ISO_CANOSC is stopped in standby mode */
#define _CGC_RSCANOSC_CLK_REQUEST_CONTINUE        (0x00000001UL) /* C_ISO_CANOSC is not stopped in standby mode */

/*
    C_ISO_CSI Source Clock Selection Register (CKSC_ICSIS_CTL)
*/
/* Source clock setting for C_ISO_CSI (ICSISCSID2,ICSISCSID1,ICSISCSID0) */
#define _CGC_CSI_CLK_SOURCE_DISABLE               (0x00000000UL) /* Disabled */
#define _CGC_CSI_CLK_SOURCE_PPLLCLK               (0x00000001UL) /* PPLLCLK (default) */
#define _CGC_CSI_CLK_SOURCE_MAINOSC               (0x00000003UL) /* Main OSC */
#define _CGC_CSI_CLK_SOURCE_HSOSC                 (0x00000004UL) /* HS IntOSC */

/*
    C_ISO_IIC Source Clock Selection Register (CKSC_IIICS_CTL)
*/
/* Source clock setting for C_ISO_IIC (IIICSCSID1,IIICSCSID0) */
#define _CGC_IIC_CLK_SOURCE_DISABLE               (0x00000000UL) /* Disabled */
#define _CGC_IIC_CLK_SOURCE_PPLLCLK2              (0x00000001UL) /* PPLLCLK2 (default) */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _CGC_MAINOSC_STABILIZE_TIME               (0x000044C0UL) /* the count value for the MainOSC stabilization counter */
#define _CGC_SUBOSC_STABILIZE_TIME                (0x010C8E00UL) /* the count value for the SubOSC stabilization counter */
#define _CGC_PLL_DIVISION_RATIO                   (0x0000083BUL) /* Division ratio Mr is set */
#define _CGC_FOUT_DIVISION_RATIO                  (0x00000001UL) /* Clock divider N */
#define _CGC_MOSCC_DEFAULT_VALUE                  (0x00000004UL) /* MOSCC default value */
#define _CGC_MOSCSTPM_DEFAULT_VALUE               (0x00000002UL) /* MOSCSTPM default value */
#define _CGC_ROSCSTPM_DEFAULT_VALUE               (0x00000002UL) /* ROSCSTPM default value */
#define _CGC_PLLC_DEFAULT_VALUE                   (0x00010300UL) /* PLLC default value */
#define _CGC_CKSC_AWDTAD_STPM_DEFAULT_VALUE       (0x00000002UL) /* CKSC_AWDTAD_STPM default value */
#define _CGC_CKSC_ATAUJD_STPM_DEFAULT_VALUE       (0x00000002UL) /* CKSC_ATAUJD_STPM default value */
#define _CGC_CKSC_ARTCAD_STPM_DEFAULT_VALUE       (0x00000002UL) /* CKSC_ARTCAD_STPM default value */
#define _CGC_CKSC_AADCAD_STPM_DEFAULT_VALUE       (0x00000002UL) /* CKSC_AADCAD_STPM default value */
#define _CGC_CKSC_AFOUTS_STPM_DEFAULT_VALUE       (0x00000002UL) /* CKSC_AFOUTS_STPM default value */
#define _CGC_CKSC_ILIND_STPM_DEFAULT_VALUE        (0x00000002UL) /* CKSC_ILIND_STPM default value */
#define _CGC_CKSC_ICANS_STPM_DEFAULT_VALUE        (0x00000002UL) /* CKSC_ICANS_STPM default value */
#define _CGC_CKSC_ICANOSCD_STPM_DEFAULT_VALUE     (0x00000002UL) /* CKSC_ICANOSCD_STPM default value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_CGC_Create(void);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif