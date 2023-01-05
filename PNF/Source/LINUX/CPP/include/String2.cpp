#ifndef String2_cpp
#define String2_cpp


/*
* This code was based off of code in Sam's Teach Yourself C++ in Just 21 Days *
*/


/*
Copyright (C) 2022 Dennis Earl Smiley


This file is part of desLib.

PNF is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

PNF is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with desLib.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
CHANGELOG
=========
3/1/22 Original a - 1. The first version.
*/


#include "String2.hpp"


String2::String2()
{
 str = new char;
 *str = "";
}

String2::String2(char * s)
{
 str = new char[strlen(s) + 1];
 strcpy(str, s);
}

String2::String2(char c)
{
 str = new char[2];

 str[0] = c;
 str[1] = '\0';
}

String2::String2(unsigned long l)
{
 str = new char[l + 1];
 for (unsigned long i = 0; i != l; ++i)
  str[i] = ' ';
 str[l + 1] = '\0';
}

String2::String2(const String2 & r)
{
 str = new char[strlen(r.str) + 1];
 strcpy(str, r.str);
}
        
String2::~String2()
{
 delete[] str;
}        
      
char & String2::operator[](unsigned long offset)
{
 return str[offset];
}

char String2::operator[](unsigned long offset) const
{
 return str[offset];
}

String2 String2::operator+(String2 s)
{
 String2 ret = (String2)str + s;
 
 
 return ret;
}

String2 String2::operator+(char c)
{
 String2 temp(c);
 
 String2 ret = (String2)str + temp;
 
 
 return ret;
}

void String2::operator+=(String2 s)
{
 (String2)str += s.getString();
}

void String2::operator+=(char * s)
{
 str = s;
}

void String2::operator+=(char c)
{
 str = str + c;
}

bool String2::operator==(String2 s)
{
 return getString() == s.getString();
}

bool String2::operator!=(String2 s)
{
 return getString() != s.getString();
}

bool String2::operator<(String2 s)
{
 return getString() < s.getString();
}

bool String2::operator>(String2 s)
{
 return getString() > s.getString();
}

bool String2::operator<=(String2 s)
{
 return getString() <= s.getString();
}

bool String2::operator>=(String2 s)
{
 return getString() >= s.getString();
}

String2 String2::operator=(const String2 & s)
{
 if (this == &s)
  return *this;
  
 str = new char[s.length() + 1];
 strcpy(str, s.getString());
 
 return (*this);
}

char * String2::getString()
{
 char * temp = new char[length() + 1];
 strcpy(temp, str);
 return temp;
}

void String2::setString()
{
 str = new char;
 *str = ' ';
}

void String2::setString(char * s)
{
 int i = strlen(s);
 str = new char[i + 1];
 strcpy(str, s);
}

unsigned long String2::length()
{
 return strlen(str);
}

unsigned long String2::size()
{
 return length();
}

unsigned long String2::begin()
{
 return 0;
}

unsigned long String2::end()
{
 return length();
}

unsigned long String2::rbegin()
{
 return end();
}

unsigned long String2::rend()
{
 return begin();
}

void String2::clear()
{
 str = new char;
 *str = "";
}

void String2::from_long(unsigned long l)
{
 switch (l)
 {
  case 0:
   str = "0";
   break;

  case 1:
       str = "1";
       break;

  case 2:
       str = "2";
       break;

  case 3:
       str = "3";
       break;

  case 4:
       str = "4";
       break;

  case 5:
       str = "5";
       break;

  case 6:
       str = "6";
       break;

  case 7:
       str = "7";
       break;

  case 8:
       str = "8";
       break;

  case 9:
       str = "9";
       break;

  case 10:
       str = "10";
       break;

  case 11:
       str = "11";
       break;

  case 12:
       str = "12";
       break;

  case 13:
       str = "13";
       break;

  case 14:
       str = "14";
       break;

  case 15:
       str = "15";
       break;

  case 16:
       str = "16";
       break;

  case 17:
       str = "17";
       break;

  case 18:
       str = "18";
       break;

  case 19:
       str = "19";
       break;

  case 20:
       str = "20";
       break;

  case 21:
       str = "21";
       break;

  case 22:
       str = "22";
       break;

  case 23:
       str = "23";
       break;

  case 24:
       str = "24";
       break;

  case 25:
       str = "25";
       break;

  case 26:
       str = "26";
       break;

  case 27:
       str = "27";
       break;

  case 28:
       str = "28";
       break;

  case 29:
       str = "29";
       break;

  case 30:
       str = "30";
       break;

  case 31:
       str = "31";
       break;

  case 32:
       str = "32";
       break;

  case 33:
       str = "33";
       break;

  case 34:
       str = "34";
       break;

  case 35:
       str = "35";
       break;

  case 36:
       str = "36";
       break;

  case 37:
       str = "37";
       break;

  case 38:
       str = "38";
       break;

  case 39:
       str = "39";
       break;

  case 40:
       str = "40";
       break;

  case 41:
       str = "41";
       break;

  case 42:
       str = "42";
       break;

  case 43:
       str = "43";
       break;

  case 44:
       str = "44";
       break;

  case 45:
       str = "45";
       break;

  case 46:
       str = "46";
       break;

  case 47:
       str = "47";
       break;

  case 48:
       str = "48";
       break;

  case 49:
       str = "49";
       break;

  case 50:
       str = "50";
       break;

  case 51:
       str = "51";
       break;

  case 52:
       str = "52";
       break;

  case 53:
       str = "53";
       break;

  case 54:
       str = "54";
       break;

  case 55:
       str = "55";
       break;

  case 56:
       str = "56";
       break;

  case 57:
       str = "57";
       break;

  case 58:
       str = "58";
       break;

  case 59:
       str = "59";
       break;

  case 60:
       str = "60";
       break;

  case 61:
       str = "61";
       break;

  case 62:
       str = "62";
       break;

  case 63:
       str = "63";
       break;

  case 64:
       str = "64";
       break;

  case 65:
       str = "65";
       break;

  case 66:
       str = "66";
       break;

  case 67:
       str = "67";
       break;

  case 68:
       str = "68";
       break;

  case 69:
       str = "69";
       break;

  case 70:
       str = "70";
       break;

  case 71:
       str = "71";
       break;

  case 72:
       str = "72";
       break;

  case 73:
       str = "73";
       break;

  case 74:
       str = "74";
       break;

  case 75:
       str = "75";
       break;

  case 76:
       str = "76";
       break;

  case 77:
       str = "77";
       break;

  case 78:
       str = "78";
       break;

  case 79:
       str = "79";
       break;

  case 80:
       str = "80";
       break;

  case 81:
       str = "81";
       break;

  case 82:
       str = "82";
       break;

  case 83:
       str = "83";
       break;

  case 84:
       str = "84";
       break;

  case 85:
       str = "85";
       break;

  case 86:
       str = "86";
       break;

  case 87:
       str = "87";
       break;

  case 88:
       str = "88";
       break;

  case 89:
       str = "89";
       break;

  case 90:
       str = "90";
       break;

  case 91:
       str = "91";
       break;

  case 92:
       str = "92";
       break;

  case 93:
       str = "93";
       break;

  case 94:
       str = "94";
       break;

  case 95:
       str = "95";
       break;

  case 96:
       str = "96";
       break;

  case 97:
       str = "97";
       break;

  case 98:
       str = "98";
       break;

  case 99:
       str = "99";
       break;

  case 100:
       str = "100";
       break;

  case 101:
       str = "101";
       break;

  case 102:
       str = "102";
       break;

  case 103:
       str = "103";
       break;

  case 104:
       str = "104";
       break;

  case 105:
       str = "105";
       break;

  case 106:
       str = "106";
       break;

  case 107:
       str = "107";
       break;

  case 108:
       str = "108";
       break;

  case 109:
       str = "109";
       break;

  case 110:
       str = "110";
       break;

  case 111:
       str = "111";
       break;

  case 112:
       str = "112";
       break;

  case 113:
       str = "113";
       break;

  case 114:
       str = "114";
       break;

  case 115:
       str = "115";
       break;

  case 116:
       str = "116";
       break;

  case 117:
       str = "117";
       break;

  case 118:
       str = "118";
       break;

  case 119:
       str = "119";
       break;

  case 120:
       str = "120";
       break;

  case 121:
       str = "121";
       break;

  case 122:
       str = "122";
       break;

  case 123:
       str = "123";
       break;

  case 124:
       str = "124";
       break;

  case 125:
       str = "125";
       break;

  case 126:
       str = "126";
       break;

  case 127:
       str = "127";
       break;

  case 128:
       str = "128";
       break;

  case 129:
       str = "129";
       break;

  case 130:
       str = "130";
       break;

  case 131:
       str = "131";
       break;

  case 132:
       str = "132";
       break;

  case 133:
       str = "133";
       break;

  case 134:
       str = "134";
       break;

  case 135:
       str = "135";
       break;

  case 136:
       str = "136";
       break;

  case 137:
       str = "137";
       break;

  case 138:
       str = "138";
       break;

  case 139:
       str = "139";
       break;

  case 140:
       str = "140";
       break;

  case 141:
       str = "141";
       break;

  case 142:
       str = "142";
       break;

  case 143:
       str = "143";
       break;

  case 144:
       str = "144";
       break;

  case 145:
       str = "145";
       break;

  case 146:
       str = "146";
       break;

  case 147:
       str = "147";
       break;

  case 148:
       str = "148";
       break;

  case 149:
       str = "149";
       break;

  case 150:
       str = "150";
       break;

  case 151:
       str = "151";
       break;

  case 152:
       str = "152";
       break;

  case 153:
       str = "153";
       break;

  case 154:
       str = "154";
       break;

  case 155:
       str = "155";
       break;

  case 156:
       str = "156";
       break;

  case 157:
       str = "157";
       break;

  case 158:
       str = "158";
       break;

  case 159:
       str = "159";
       break;

  case 160:
       str = "160";
       break;

  case 161:
       str = "161";
       break;

  case 162:
       str = "162";
       break;

  case 163:
       str = "163";
       break;

  case 164:
       str = "164";
       break;

  case 165:
       str = "165";
       break;

  case 166:
       str = "166";
       break;

  case 167:
       str = "167";
       break;

  case 168:
       str = "168";
       break;

  case 169:
       str = "169";
       break;

  case 170:
       str = "170";
       break;

  case 171:
       str = "171";
       break;

  case 172:
       str = "172";
       break;

  case 173:
       str = "173";
       break;

  case 174:
       str = "174";
       break;

  case 175:
       str = "175";
       break;

  case 176:
       str = "176";
       break;

  case 177:
       str = "177";
       break;

  case 178:
       str = "178";
       break;

  case 179:
       str = "179";
       break;

  case 180:
       str = "180";
       break;

  case 181:
       str = "181";
       break;

  case 182:
       str = "182";
       break;

  case 183:
       str = "183";
       break;

  case 184:
       str = "184";
       break;

  case 185:
       str = "185";
       break;

  case 186:
       str = "186";
       break;

  case 187:
       str = "187";
       break;

  case 188:
       str = "188";
       break;

  case 189:
       str = "189";
       break;

  case 190:
       str = "190";
       break;

  case 191:
       str = "191";
       break;

  case 192:
       str = "192";
       break;

  case 193:
       str = "193";
       break;

  case 194:
       str = "194";
       break;

  case 195:
       str = "195";
       break;

  case 196:
       str = "196";
       break;

  case 197:
       str = "197";
       break;

  case 198:
       str = "198";
       break;

  case 199:
       str = "199";
       break;

  case 200:
       str = "200";
       break;

  case 201:
       str = "201";
       break;

  case 202:
       str = "02";
       break;

  case 203:
       str = "203";
       break;

  case 204:
       str = "204";
       break;

  case 205:
       str = "205";
       break;

  case 206:
       str = "206";
       break;

  case 207:
       str = "207";
       break;

  case 208:
       str = "208";
       break;

  case 209:
       str = "209";
       break;

  case 210:
       str = "210";
       break;

  case 211:
       str = "211";
       break;

  case 212:
       str = "212";
       break;

  case 213:
       str = "213";
       break;

  case 214:
       str = "214";
       break;

  case 215:
       str = "215";
       break;

  case 216:
       str = "216";
       break;

  case 217:
       str = "217";
       break;

  case 218:
       str = "218";
       break;

  case 219:
       str = "219";
       break;

  case 220:
       str = "220";
       break;

  case 221:
       str = "221";
       break;

  case 222:
       str = "222";
       break;

  case 223:
       str = "223";
       break;

  case 224:
       str = "224";
       break;

  case 225:
       str = "225";
       break;

  case 226:
       str = "226";
       break;

  case 227:
       str = "227";
       break;

  case 228:
       str = "228";
       break;

  case 229:
       str = "229";
       break;

  case 230:
       str = "230";
       break;

  case 231:
       str = "231";
       break;

  case 232:
       str = "232";
       break;

  case 233:
       str = "233";
       break;

  case 234:
       str = "234";
       break;

  case 235:
       str = "235";
       break;

  case 236:
       str = "236";
       break;

  case 237:
       str = "237";
       break;

  case 238:
       str = "238";
       break;

  case 239:
       str = "239";
       break;

  case 240:
       str = "240";
       break;

  case 241:
       str = "241";
       break;

  case 242:
       str = "242";
       break;

  case 243:
       str = "243";
       break;

  case 244:
       str = "244";
       break;

  case 245:
       str = "245";
       break;

  case 246:
       str = "246";
       break;

  case 247:
       str = "247";
       break;

  case 248:
       str = "248";
       break;

  case 249:
       str = "249";
       break;

  case 250:
       str = "250";
       break;

  case 251:
       str = "251";
       break;

  case 252:
       str = "252";
       break;

  case 253:
       str = "253";
       break;

  case 254:
       str = "254";
       break;

  case 255:
       str = "255";
       break;

  case 256:
       str = "256";
       break;

  case 257:
       str = "257";
       break;

  case 258:
       str = "258";
       break;

  case 259:
       str = "259";
       break;

  case 260:
       str = "260";
       break;

  case 261:
       str = "261";
       break;

  case 262:
       str = "262";
       break;

  case 263:
       str = "263";
       break;

  case 264:
       str = "264";
       break;

  case 265:
       str = "265";
       break;

  case 266:
       str = "266";
       break;

  case 267:
       str = "267";
       break;

  case 268:
       str = "268";
       break;

  case 269:
       str = "269";
       break;

  case 270:
       str = "270";
       break;

  case 271:
       str = "271";
       break;

  case 272:
       str = "272";
       break;

  case 273:
       str = "273";
       break;

  case 274:
       str = "274";
       break;

  case 275:
       str = "275";
       break;

  case 276:
       str = "276";
       break;

  case 277:
       str = "277";
       break;

  case 278:
       str = "278";
       break;

  case 279:
       str = "279";
       break;

  case 280:
       str = "280";
       break;

  case 281:
       str = "281";
       break;

  case 282:
       str = "282";
       break;

  case 283:
       str = "283";
       break;

  case 284:
       str = "284";
       break;

  case 285:
       str = "285";
       break;

  case 286:
       str = "286";
       break;

  case 287:
       str = "287";
       break;

  case 288:
       str = "288";
       break;

  case 289:
       str = "289";
       break;

  case 290:
       str = "290";
       break;

  case 291:
       str = "291";
       break;

  case 292:
       str = "292";
       break;

  case 293:
       str = "293";
       break;

  case 294:
       str = "294";
       break;

  case 295:
       str = "295";
       break;

  case 296:
       str = "296";
       break;

  case 297:
       str = "297";
       break;

  case 298:
       str = "298";
       break;

  case 299:
       str = "299";
       break;

  case 300:
       str = "300";
       break;

  case 301:
       str = "301";
       break;

  case 302:
       str = "302";
       break;

  case 303:
       str = "303";
       break;

  case 304:
       str = "304";
       break;

  case 305:
       str = "305";
       break;

  case 306:
       str = "306";
       break;

  case 307:
       str = "307";
       break;

  case 308:
       str = "308";
       break;

  case 309:
       str = "309";
       break;

  case 310:
       str = "310";
       break;

  case 311:
       str = "311";
       break;

  case 312:
       str = "312";
       break;

  case 313:
       str = "313";
       break;

  case 314:
       str = "314";
       break;

  case 315:
       str = "315";
       break;

  case 316:
       str = "316";
       break;

  case 317:
       str = "317";
       break;

  case 318:
       str = "318";
       break;

  case 319:
       str = "319";
       break;

  case 320:
       str = "320";
       break;

  case 321:
       str = "321";
       break;

  case 322:
       str = "322";
       break;

  case 323:
       str = "323";
       break;

  case 324:
       str = "324";
       break;

  case 325:
       str = "325";
       break;

  case 326:
       str = "326";
       break;

  case 327:
       str = "327";
       break;

  case 328:
       str = "328";
       break;

  case 329:
       str = "329";
       break;

  case 330:
       str = "330";
       break;

  case 331:
       str = "331";
       break;

  case 332:
       str = "332";
       break;

  case 333:
       str = "333";
       break;

  case 334:
       str = "334";
       break;

  case 335:
       str = "335";
       break;

  case 336:
       str = "336";
       break;

  case 337:
       str = "337";
       break;

  case 338:
       str = "338";
       break;

  case 339:
       str = "339";
       break;

  case 340:
       str = "340";
       break;

  case 341:
       str = "342";
       break;

  case 343:
       str = "343";
       break;

  case 344:
       str = "344";
       break;

  case 345:
       str = "345";
       break;

  case 346:
       str = "346";
       break;

  case 347:
       str = "347";
       break;

  case 348:
       str = "348";
       break;

  case 349:
       str = "349";
       break;

  case 350:
       str = "350";
       break;

  case 351:
       str = "351";
       break;

  case 352:
       str = "352";
       break;

  case 353:
       str = "353";
       break;

  case 354:
       str = "354";
       break;

  case 355:
       str = "355";
       break;

  case 356:
       str = "356";
       break;

  case 357:
       str = "357";
       break;

  case 358:
       str = "358";
       break;

  case 359:
       str = "359";
       break;

  case 360:
       str = "360";
       break;

  case 361:
       str = "361";
       break;

  case 362:
       str = "362";
       break;

  case 363:
       str = "363";
       break;

  case 364:
       str = "364";
       break;

  case 365:
       str = "365";
       break;

  case 366:
       str = "366";
       break;

  case 367:
       str = "367";
       break;

  case 368:
       str = "368";
       break;

  case 369:
       str = "369";
       break;

  case 370:
       str = "370";
       break;

  case 371:
       str = "371";
       break;

  case 372:
       str = "372";
       break;

  case 373:
       str = "373";
       break;

  case 374:
       str = "374";
       break;

  case 375:
       str = "375";
       break;

  case 376:
       str = "376";
       break;

  case 377:
       str = "377";
       break;

  case 378:
       str = "378";
       break;

  case 379:
       str = "379";
       break;

  case 380:
       str = "380";
       break;

  case 381:
       str = "381";
       break;

  case 382:
       str = "382";
       break;

  case 383:
       str = "383";
       break;

  case 384:
       str = "384";
       break;

  case 385:
       str = "385";
       break;

  case 386:
       str = "386";
       break;

  case 387:
       str = "387";
       break;

  case 388:
       str = "388";
       break;

  case 389:
       str = "389";
       break;

  case 390:
       str = "390";
       break;

  case 391:
       str = "391";
       break;

  case 392:
       str = "392";
       break;

  case 393:
       str = "393";
       break;

  case 394:
       str = "394";
       break;

  case 395:
       str = "395";
       break;

  case 396:
       str = "396";
       break;

  case 397:
       str = "397";
       break;

  case 398:
       str = "398";
       break;

  case 399:
       str = "399";
       break;

  case 400:
       str = "400";
       break;


  default:
       str = "N/A";
       break;
 }
}

void String2::insert()
{
 String2 str2(length() + 1);
 
 unsigned long i;
 for (i = 0; i < length(); ++i)
  str2[i] = str[i];
 str2[i] = ' ';
 
 str = str2.getString();
}

void String2::remove()
{
 String2 str2(length() - 1);
 
 for (unsigned long i = 0; i < str2.length(); ++i)
  str2[i] = str[i];
 str = str2.getString();
}

void String2::insert(unsigned long offset, char d)
{
 unsigned long len;
 
 if (offset >= length())
  len = offset + 1;
 else
  len = length();
 String2 str2(len);
 
 for (unsigned long i = 0; i < len; ++i)
 { 
  if (i == offset)
  {
   str2[i] = d;
  }
  else
  {     
   if (i >= length())
   {
   	str2[i] = ' ';
   	continue;
   }
   str2[i] = str[i];
  }
 }
 str = str2.getString();
}

void String2::remove(unsigned long offset)
{
 unsigned long len;
 
 if (offset >= length())
 {
  cout << "* ERROR: Index out of bounds. index = " << offset << "\n";
  return;
 }
 else
  len = length() - 1;
   
 String2 str2(len);
 
 for (unsigned long i = 0; i < len; ++i)
 {
  if (i == offset)
   continue;
  else
   str2[i] = str[i];
 }
 str = str2.getString(); 
}


ostream & operator<<(ostream & stream, String2 s)
{
 stream << s.getString();
 
 
 return stream;
}

istream & operator>>(istream & stream, String2 & s)
{
 string temp;
 getline(stream, temp);
 s = (char *)temp.c_str();
 
 
 return stream;
}

String2 String2::reverse()
{
 String2 ret = "";
 for (unsigned long i = length(); i != 0; --i)
  ret += this[i];


 return ret;
}


#endif // String2_cpp
