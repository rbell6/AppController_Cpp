//
//  AppController.cpp
//
//  Created by richard bell on 12/4/13.
//  Copyright (c) 2013 richard bell. All rights reserved.
//
#include "AppController.h"
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <unistd.h>

using namespace std;
using namespace RBell;

mutex m;

void AppController::DoTasks(map<string, void*> params)
{
   m.lock();
   _status = WAIT;
   vector<IAction*> actions = *((vector<IAction*> *)params["actions"]);
   map<string, void*> data = *((map<string, void*> *)params["data"]);
   for (int i = 0; i < actions.size(); i++)
   {
      actions[i]->Execute(data);
   }
   _status = CONTINUE;
   m.unlock();
}

bool something()
{
   return true;
}

AppController::AppController()
{
   
}


void AppController::HandleRequest(string command)
{
   map<string, void*> empty;
   HandleRequest(command, false, empty);
}


void AppController::HandleRequest(string command, bool async)
{
   map<string, void*> empty;
   HandleRequest(command, async, empty);
}

void AppController::HandleRequest(string command, bool async, map<string, void*> params)
{
   vector<IAction*> actions;
   
   if (ValidationMap.find(command) != ValidationMap.end())
   {
      actions.push_back(ValidationMap[command]);
   }
   if (DataMap.find(command) != DataMap.end())
   {
      actions.push_back(DataMap[command]);
   }
   if (ViewMap.find(command) != ViewMap.end())
   {
      actions.push_back(ViewMap[command]);
   }
   if (ErrorMap.find(command) != ErrorMap.end())
   {
      actions.push_back(ErrorMap[command]);
   }
   map<string, void*> p;
   p["actions"] = &actions;
   p["data"] = &params;
   
   if (async)
   {
      thread t(&AppController::DoTasks, this, p);
   }
   else
   {
      DoTasks(p);
   }
}


/*void AppController::operator [](string command)
{
   map<string, void*> empty;
   HandleRequest(command, false, empty);
}*/

void AppController::MapCommandToValidationAction(string command, IAction* action)
{
   ValidationMap[command] = action;
}

void AppController::MapCommandToDataAction(string command, IAction* action)
{
   DataMap[command] = action;
}

void AppController::MapCommandViewAction(string command, IAction* action)
{
   ViewMap[command] = action;
}

void AppController::MapCommandToErrorAction(string command, IAction* action)
{
   ErrorMap[command] = action;
}