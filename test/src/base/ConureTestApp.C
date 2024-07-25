//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ConureTestApp.h"
#include "ConureApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
ConureTestApp::validParams()
{
  InputParameters params = ConureApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

ConureTestApp::ConureTestApp(InputParameters parameters) : MooseApp(parameters)
{
  ConureTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

ConureTestApp::~ConureTestApp() {}

void
ConureTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  ConureApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"ConureTestApp"});
    Registry::registerActionsTo(af, {"ConureTestApp"});
  }
}

void
ConureTestApp::registerApps()
{
  registerApp(ConureApp);
  registerApp(ConureTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ConureTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ConureTestApp::registerAll(f, af, s);
}
extern "C" void
ConureTestApp__registerApps()
{
  ConureTestApp::registerApps();
}
