/*
 language Copyright (C) 2015 Dennis Earl Smiley
 This software is distributed under the terms of des Software License a a-a-e or at your option any later version. This software is alpha as of 6/26/15.
 Contact info despersonal000@gmail.com
*/
/*
 CHANGELOG
 =========
 * 6/26/15 Original a - The first version.
 * 6/26/15 Original a-a - 1. Fixed bugs...
 * 7/26/15 Original a-a-a - 1. Restored from file
 							2. Fixed bugs...
 							3. Added support for pnfha
 							4. Removed support for pnfha. Might add in future version. Used comments to do so.
*/
#include <desLib/desLib.hpp>
#include <process.h>


int main(int argc, char ** argv)
{
 if (argc == 2)
 {
  if (strcmp(argv[1], "-usage") == 0)
  {
   cout << "Usage: <language> [-usage] [-liscense] [-languages]\n"
   		<< "\n"
   		<< "\n"
   		<< "-usage     - Prints a usage message.\n"
   		<< "-liscense  - Prints out the liscense info for this program.\n"
   		<< "-languages - Gives a list of languages you can use.\n"
   		<< "\n";
   return 0;
  }
  else if (strcmp(argv[1], "-liscense") == 0)
  {
   cout << "For liscense information, see \"des_Software_Liscense_a-a-a-e.txt\" in your\n"
   		<< "Documentation folder."
		<< "\n";
    
    
   return 0;
    
   return 0;
  }
  else if (strcmp(argv[1], "-languages") == 0)
  {
   cout << "Languages:\n"
   		<< "\n"
   		<< "pnf\n"
   		<< "pnfasm\n"
   		//<< "pnfha\n"
   		<< "pnfpp\n"
   		<< "\n";
   		
   		
   return 0;
  }
  else
  {
   if (strcmp(argv[1], "pnf") == 0)
   {
    error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
    return 1;
   }
   else
   {
    error(ERRORMSG, (char *)"Wrong arguments. Try -usage.");
    return 1;
   } 
  }
 }
 else if (argc == 3)
 {
  if (strcmp(argv[1], "pnf") == 0)
  {
   if (strcmp(argv[2], "-usage") == 0)
   {
   	cout << "Usage: <language> <pnf> [-usage] [-liscense] [-instructions] [-tutorial] [-run \n"
	     << "       <program> [arguments]] [-compile <pnffile> <C++ file>] [-mklib <pnffile>\n"
		 << "       <plib file>]\n"
   		 << "\n"
   		 << "-usage        - Gives help on the usage.\n"
   		 << "-liscense     - Prints out the liscense info for this program.\n"
   		 << "-instructions - Prints out the instruction info for this program.\n"
   		 << "-tutorial     - Prints out tutorial information for this program.\n"
   		 << "-extensions   - Prints out extension information for this program.\n"
   		 << "-run          - Runs the program, with the specified arguments.\n"
   		 << "-compile      - Compiles a PNF program.\n"
   		 << "-mklib        - Makes a PNF library out of a PNF program.\n"
   		 << "\n";
   		 
   	return 0;
   }
   else if (strcmp(argv[2], "-liscense") == 0)
   {
    cout << "For liscense information, see \"des_Software_Liscense_a-a-a-e.txt\" in your\n"
   	 	 << "Documentation folder."
   	 	 << "\n";
    
    return 0;
   }
   else if (strcmp(argv[2], "-instructions") == 0)
   {
   	cout << "For instruction set information, see \"instruction_set.txt\" in your Documentation"
	   	 << "folder."
   		 << "\n";
   		 
   	return 0;
   }
   else if (strcmp(argv[2], "-tutorial") == 0)
   {
   	cout << "For a tutorial of this language, see \"PNF-tutorial.txt\" in your Documentation\n"
	   	 << "folder."
   		 << "\n";
   		 
   	return 0;
   }
   else if (strcmp(argv[2], "-extensions") == 0)
   {
   	cout << "For the valid extensions for this language, see \"PNF-extensions.txt\" in your \n"
	     << "Documentation folder."
   		 << "\n";
   		 
    return 0;
   }
   else
   {
    error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
    return 1;
   }
  }
  else if (strcmp(argv[1], "pnfasm") == 0)
  {
   if (strcmp(argv[2], "-usage") == 0)
   {
    cout << "Usage: <language> <pnfasm> [-usage] [-liscense] [-instructions] [-tutorial] \n"
	    << "       [-compile <pnfasmfile> <pnffile>]\n"
   		 << "\n"
   		 << "-usage        - Gives help on the usage.\n"
   		 << "-liscense     - Prints out the liscense info for this program.\n"
   		 << "-instructions - Prints out the instruction info for this program.\n"
   		 << "-tutorial     - Prints out tutorial information for this program.\n"
		 << "-extensions   - Prints out extension information for this program.\n"   		 
   		 << "-compile      - Compiles a PNFASM program.\n"
   		 << "\n";
   		
    return 0;
   }
   else if (strcmp(argv[2], "-liscense") == 0)
   {
    cout << "For liscense information, see \"des_Software_Liscense_a-a-a-e.txt\" in your\n"
   	 	 << "Documentation folder."
   	 	 << "\n";
    
    return 0;
   }
   else if (strcmp(argv[2], "-instructions") == 0)
   {
   	cout << "For instruction set information, see \"instruction_set.txt\" in your Documentation"
	   	 << "folder."
   		 << "\n";
   		 
   	return 0;
   }
   else if (strcmp(argv[2], "-tutorial") == 0)
   {
   	cout << "For a tutorial of this language, see \"PNFASM-tutorial.txt\" in your Documentation"
	   	 << "folder."
   		 << "\n";
   		 
   	return 0;
   }
   else if (strcmp(argv[2], "-extensions") == 0)
   {
   	cout << "For the valid extensions for this language, see \"PNFASM-extensions.txt\" in your\n"
	     << "Documentation folder."
   		 << "\n";
   		 
    return 0;
   }
   else
   {
    error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
    return 1;
   }
  }
  /*
  else if (strcmp(argv[1], "pnfha") == 0)
  {
   if (strcmp(argv[2], "-usage") == 0)
   {
    cout << "Usage: <language> <pnfha> [-usage] [-liscense] [-syntax] [-tutorial] \n"
	    << "       [-compile <pnfhafile> <pnfasmfile>]\n"
   		 << "\n"
   		 << "-usage        - Gives help on the usage.\n"
   		 << "-liscense     - Prints out the liscense info for this program.\n"
   		 << "-syntax       - Prints out the instruction info for this program.\n"
   		 << "-tutorial     - Prints out tutorial information for this program.\n"   		 
   		 << "-compile      - Compiles a PNFHA program.\n"
   		 << "\n";
   		
    return 0;
   }
   else if (strcmp(argv[2], "-liscense") == 0)
   {
    cout << "For liscense information, see \"des_Software_Liscense_a-a-a-e.txt\" in your\n"
   	 	 << "Documentation folder."
   	 	 << "\n";
    
    return 0;
   }
   else if (strcmp(argv[2], "-syntax") == 0)
   {
   	cout << "For instruction set information, see \"pnfha.txt\" in your Documentation"
	   	 << "folder."
   		 << "\n";
   		 
   	return 0;
   }
   else if (strcmp(argv[2], "-tutorial") == 0)
   {
   	cout << "For a tutorial of this language, see \"PNFHA-tutorial.txt\" in your Documentation"
	   	 << "folder."
   		 << "\n";
   		 
   	return 0;
   }
   else
   {
    error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
    return 1;
   }
  }*/
  else if (strcmp(argv[1], "pnfpp") == 0)
  {
   if (strcmp(argv[2], "-usage") == 0)
   {
   	cout << "Usage: <language> <pnfpp> [-usage] [-liscense] [-tutorial] \n"
	    << "       [-preprocess <inputfile> <outputfile>]\n"
   		 << "\n"
   		 << "-usage        - Gives help on the usage.\n"
   		 << "-liscense     - Prints out the liscense info for this program.\n"   		 
   		 << "-tutorial     - Prints out tutorial information for this program.\n"   		 
   		 << "-preprocess   - Preprocesses a file.\n"
   		 << "\n";
   		 
   	return 0;
   }
   else if (strcmp(argv[2], "-liscense") == 0)
   {
   	cout << "For liscense information, see \"des_Software_Liscense_a-a-a-e.txt\" in your\n"
   	 	 << "Documentation folder."
   	 	 << "\n";
   	 	 
    return 0;
   }
   else if (strcmp(argv[2], "-tutorial") == 0)
   {
   	cout << "For a tutorial of this language, see \"PNFPP-tutorial.txt\" in your Documentation"
	   	 << "folder."
   		 << "\n";
   		 
   	return 0;
   }
   else
   {
    error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
    return 1;
   }
  }
  else
  {
   error(ERRORMSG, (char *)"Wrong arguments. Try -usage.");
   return 1;
  }
 }
 else if (argc > 3)
 {
  if (strcmp(argv[1], "pnf") == 0)
  {
   if (strcmp(argv[2], "-run") == 0)
   {
    Array<String> args;
   
    args[0] = (char *)"PNF";
    for (unsigned long i = 3, j = 1; i < argc; ++i, ++j)
    {
 	 args.insert();
   	 
     args[j] = argv[i];
    }
    args.insert();
    args[args.length() - 1] = (char *)"";
   
    char ** args2 = new char * [args.length()];
    for (unsigned long i = 0; i < args.length(); ++i)
     args2[i] = (char *)args[i].getString().c_str();
    
    args2[args.length() - 1] = NULL;
   
   
    int ret = _spawnvp(_P_WAIT, "PNF", args2);
    delete args2;
   
    if (ret == -1 && errno != 0)
    {
   	 ret = 1;
   	 error(ERRORMSG, (char*)"Error running PNF program.");
    }
   
    return ret;
   }
   else if (strcmp(argv[2], "-compile") == 0)
   {
   	if (argc == 5)
   	{
   	 int ret = _spawnlp(_P_WAIT, "PNF2CPP", "PNF2CPP", argv[3], argv[4], NULL);
   
     if (ret == -1 && errno != 0)
     {
  	  ret = 1;
  	  error(ERRORMSG, (char*)"Error running PNF2CPP program.");
     }
   
     return ret;
    }
    else
    {
     error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
     return 1;
    }
   }
   else if (strcmp(argv[2], "-mklib") == 0)
   {
   	if (argc == 5)
   	{
   	 int ret = _spawnlp(_P_WAIT, "MKPNFLIB", "MKPNFLIB", argv[3], argv[4], NULL);
   
     if (ret == -1 && errno != 0)
     {
  	  ret = 1;
  	  error(ERRORMSG, (char*)"Error running MKPNFLIB program.");
     }
   
     return ret;
   	}
   	else
    {
     error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
     return 1;
    }
   }
   else
   {
    error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
    return 1;
   }
  }
  else if (strcmp(argv[1], "pnfha") == 0)
  {
   if (strcmp(argv[2], "-compile") == 0)
   {
   	if (argc == 5)
   	{
   	 int ret = _spawnlp(_P_WAIT, "PNFHA", "PNFHA", argv[3], argv[4], NULL);
   
     if (ret == -1 && errno != 0)
     {
  	  ret = 1;
  	  error(ERRORMSG, (char*)"Error running PNFHA program.");
     }
   
     return ret;
   	}
   	else
   	{
   	 error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
     return 1;
   	}
   }
   else
   {
   	error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
    return 1;
   }
  }
  else if (strcmp(argv[1], "pnfasm") == 0)
  {
   if (strcmp(argv[2], "-compile") == 0)
   {
   	if (argc == 5)
   	{
   	 int ret = _spawnlp(_P_WAIT, "PNFASM", "PNFASM", argv[3], argv[4], NULL);
   
     if (ret == -1 && errno != 0)
     {
  	  ret = 1;
  	  error(ERRORMSG, (char*)"Error running PNFASM program.");
     }
   
     return ret;
   	}
   	else
   	{
   	 error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
     return 1;
   	}
   } 
   else
   {
   	error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
    return 1;
   }
  }
  else if (strcmp(argv[2], "-preprocess") == 0)
  {
   if (argc == 5)
   {
   	int ret = _spawnlp(_P_WAIT, "PNFPP", "PNFPP", argv[3], argv[4], NULL);
   
     if (ret == -1 && errno != 0)
     {
  	  ret = 1;
  	  error(ERRORMSG, (char*)"Error running PNFPP program.");
     }
   
     return ret;
   }
   else
   {
    error(ERRORMSG, (char *)"Wrong language arguments. Try <language> -usage.");
    return 1;
   }
  }
  else
  {
   error(ERRORMSG, (char *)"Wrong arguments. Try -usage.");
   return 1;
  }
 }
 else
 {
  error(ERRORMSG, (char *)"Wrong arguments. Try -usage.");
  return 1;
 }
}
