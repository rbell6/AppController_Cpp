//
//  AppController.h
//
//  Created by richard bell on 12/4/13.
//  Copyright (c) 2013 richard bell. All rights reserved.
//

#ifndef BST_AppController_h
#define BST_AppController_h
#include <iostream>
#include <map>
#include <vector>
#include "IAction.h"
using namespace std;

namespace RBell {
   
   class AppController
   {
   public:
      AppController();
   
      void HandleRequest(string command);
      void HandleRequest(string command, bool async);
      void HandleRequest(string command, bool async, map<string, void*> params);
      //static void operator [](string command);
      void MapCommandToValidationAction(string command, IAction* action);
      void MapCommandToDataAction(string command, IAction* action);
      void MapCommandViewAction(string command, IAction* action);
      void MapCommandToErrorAction(string command, IAction* action);
   
      static int const WAIT = 1;
      static int const CONTINUE = 0;
      static int const EXIT = 2;
      void DoTasks(map<string, void*> params);
      template <typename Type>
      static Type Convert(void* param)
      {
         Type data = *((Type *)param);
         return data;
      }
      template <typename Type>
      static void* ConvertVoid(Type* param)
      {
         void* data = ((void*)(param));
         return data;
      }
      
      
      int Status() { return _status; }
      
   private:
      map<string, IAction*> DataMap;
      map<string, IAction*> ValidationMap;
      map<string, IAction*> ViewMap;
      map<string, IAction*> ErrorMap;
      int _status;
   };
}
#endif
