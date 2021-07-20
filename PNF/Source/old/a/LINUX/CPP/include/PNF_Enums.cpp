#ifndef PNF_Enums_cpp
#define PNF_Enums_cpp
/*
    Copyright 2020 Dennis Earl Smiley

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/*
 CHANGELOG
 =========

 9/5/20 Origional a 	- The first version.
*/


enum PNF_Instruction_Enum
{
 IVERSION = 0,
 IVOID,
 ICRASH,
 IQUIT,
 IHALT,
 IPRINT,
 IPRINTLN,
 IREAD,
 ILOAD,
 ISTORE,
 ILOADC,
 ISTOREC,
 IELOAD,
 IESTORE,
 IELOADC,
 IESTOREC,
 IVLOAD,
 IVSTORE,
 IVLOADC,
 IVSTOREC,
 ISTOREA,
 IMODT,
 IMODCT,
 IADD,
 ISUB,
 IMUL,
 IDIV,
 IMOD,
 IPOW,
 IROOT,
 IINC,
 IDEC,
 IEQU,
 INEQU,
 IGTR,
 ILSS,
 IGEQU,
 ILEQU,
 IAND,
 IOR,
 INOT,
 IGOTO,
 ICGOTO,
 IZGOTO,
 IPGOTO,
 INGOTO,
 IGOTOL,
 ICGOTOL,
 IZGOTOL,
 IPGOTOL,
 INGOTOL,
 IST,
 IPUSH,
 IPOP,
 ICALL,
 ICALLL,
 IRET,
 IVAR,
 ILBL,
 IEPRINT,
 IEPRINTLN,
 IEND,
 IELBL,
 IEVLOAD,
 IHEADD,
 IHEREM,
 IHEED,
 IHEGET,
 ISHEADD,
 ISHEREM,
 ISHEED,
 ISHEGET,
 IEADD,
 IEREM,
 IEED,
 IEGET,
 IEXADD,
 IEXREM,
 IEXED,
 IEXGET,
 IIADD,
 IIREM,
 IIED,
 IIGET,
 IHEVENT,
 ISHEVENT,
 IEVENT,
 IEXCEPTION,
 IINT,
 ITYPEOF,
 ICTYPEOF,
 ITLOAD,
 IALOAD,
 IINLOAD,
 IICLOAD,
 IARLOAD,
 IATOC,
 ISWITCH,
 IVADD,
 ILADD,
 IELADD,
 IADD2V,
 IBTAND,
 IBTOR,
 IBTEXOR,
 IBTNOT,
 IBTSL,
 IBTSR,
 IVCHECK,
 IVSUPP,
 IVPRINT,
 IVPRINTLN,
 IISUPP,
 ITSUPP,
 ICOMMENT,
 IFIMODE,
 IFOMODE,
 IFIOPEN,
 IFOOPEN,
 IFREAD,
 IFPRINT,
 IFPRINTLN,
 IFICLOSE,
 IFOCLOSE,
 IMEML,
 IFIEOF,
 IARNLOAD,
 IRDSTART1,
 IRFROM1,
 IRTO1,
 IRDEND1,
 IRSTART1,
 IRANGE1,
 IREND1,
 IRLOAD1,
 IRSTORE1,
 IHEADDB,
 ISHEADDB,
 IEADDB,
 IEXADDB,
 IIADDB,
 IRDSTART2,
 IRFROM2,
 IRTO2,
 IRDEND2,
 IRSTART2,
 IRANGE2,
 IRPREP2,
 IRLOAD2,
 IESTART,
 IENAME,
 IEEND,
 IENUMS,
 IENUM,
 ISENUM,
 IEPREP,
 ILOADE,
 ISTOREE,
 IASTART,
 IAEND,
 IAPREP,
 IAIPREP,
 ILOADIA,
 ISTOREIA,
 IALENGTH,
 IAPRINT,
 IDUP,
 ICDUP,
 IIF,
 IENDIF,
 IIFELSE,
 IENDIFELSE,
 IEIF,
 IIFBEGIN,
 IIFEND,
 ISWITCH2,
 ISWBEGIN,
 ISWEND,
 ISWCASE,
 ISWCBEGIN,
 ISWCEND,
 ISWDEFAULT,
 ISWBREAK,
 ILOADSP,
 ISTORESP,
 ILOADSTACK,
 ISTORESTACK,
 IATOSP,
 ISPTOA,
 IPATCH,
 INATIVE,
 IFRET,
 IFCALL,
 IFCPARAMS,
 IFECPARAMS,
 IFECALL,
 IPNUM,
 IPARAMF,
 IPARAMF2,
 IPARAMF3,
 IRNUM,
 IRETURNF,
 IRETURNF2,
 IRETURNF3,
 IFNAME,
 IRETURNV,
 IFNCLOAD,
 IFNCSTORE,
 IFNCNEW,
 IFNCDELETE,
 IFNCSNAME,
 IFNCSRET,
 IFNCSPARAM,
 IFNCSDEF,
 IFNCGNAME,
 IFNCGRET,
 IFNCGPARAM,
 IFNCGDEF,
 IFNCPOINT,
 IFNCLENGTH,
 IFNCSYNCR,
 IFNCFIND,
 IFNCFRET,
 IFNCFPARAM,
 IFNCFBRET,
 IFNCFBPARAM,
 IFNCDEFAULT,
 IFNCDEFAULT2,
 IFNCSDEFAULTV,
 IFNCSDEFAULTV2,
 IFNCGDEFAULTV2,
 IFNCDEFAULTSYNC,
 INTIMES,
 ICMP,
 IRUN,
 IJRUN,
 IPNFRUN,
 ISTRUCT,
 ISTRUCTVAR,
 IENDSTRUCT,
 ISTRUCTNAME,
 ISTRUCTONAME,
 ISTRUCTD,
 ISTRUCTUSE,
 IENDI
};

enum PNF_Simple_Type_Enum
{
 STVOID = 0,
 STBOOLEAN,
 STNUMBER,
 STCHARACTER,
 STSTRING
};

enum PNF_Type_Enum
{
 TVOID = 0,
 TBOOLEAN,
 TNUMBER,
 TCHARACTER,
 TSTRING,
 TPSIMPLE,
 TDPSIMPLE,
 TRSIMPLE,
 TASIMPLE,
 TSIMPLE,
 TRANGET1,
 TRANGET2,
 TENUM,
 TSTRUCT,
 TOBJECT,
 TPOBJECT,
 TDOBJECT,
 TROBJECT,
 TAOBJECT,
 TENDT
};

enum PNF_Object_Type
{
 TOSIMPLE = 0,
 TORANGET1,
 TORANGET2,
 TOENUM
};

enum PNF_FMODE
{
 FMIN = 0,
 FMOUT,
 FMBINARY,
 FMATE,
 FMAPP,
 FMTRUNC
};

enum BREAKPOINT_CONTROL
{
 BCONE = 0,
 BCTWO,
 BCTHREE
};

#endif // PNF_Enums_cpp