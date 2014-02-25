//
//  IAction.h
//
//  Created by richard bell on 12/4/13.
//  Copyright (c) 2013 richard bell. All rights reserved.
//

#ifndef BST_IAction_h
#define BST_IAction_h
#include <map>
using namespace std;

namespace RBell
{
   class IAction
   {
   public:
      virtual void Execute(map<string, void*> params) = 0;
   };
}

#endif
