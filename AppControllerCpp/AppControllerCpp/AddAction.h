//
//  AddAction.h
//  AppController
//
//  Created by richard bell on 12/17/13.
//  Copyright (c) 2013 richard bell. All rights reserved.
//

#ifndef __AppController__AddAction__
#define __AppController__AddAction__

#include <iostream>
#include "AppController.h"
#include "IAction.h"
#include <map>
using namespace std;
using namespace RBell;

class AddAction : public IAction
{
public:
   void Execute(map<string, void*> params)
   {
      int num = *((int*)params["num"]);
      int num2 = *((int*)params["num2"]);
      cout << "result: " << num + num2 << endl;
   }
};

#endif /* defined(__AppController__AddAction__) */
