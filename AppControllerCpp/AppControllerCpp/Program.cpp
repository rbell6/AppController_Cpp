//
//  Program.cpp
//  AppController
//
//  Created by richard bell on 12/17/13.
//  Copyright (c) 2013 richard bell. All rights reserved.
//

#include <iostream>
#include "AppController.h"
#include "IAction.h"
#include "AddAction.h"
#include <map>
#include <unistd.h>

using namespace std;
using namespace RBell;

void test(void* data) {
   
}

int main()
{
   AppController app;
   int num = 27, num2 = 50;
   IAction* action = new AddAction;
   app.MapCommandViewAction("shownum", action);
   map<string, void*> params;
   params["num"] = &num;
   params["num2"] = &num2;
   app.HandleRequest("shownum", false, params);
   
   while (app.Status() == AppController::WAIT);
   
   return 0;
}
