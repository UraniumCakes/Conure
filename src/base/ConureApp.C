#include "ConureApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
ConureApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

ConureApp::ConureApp(InputParameters parameters) : MooseApp(parameters)
{
  ConureApp::registerAll(_factory, _action_factory, _syntax);
}

ConureApp::~ConureApp() {}

void
ConureApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<ConureApp>(f, af, s);
  Registry::registerObjectsTo(f, {"ConureApp"});
  Registry::registerActionsTo(af, {"ConureApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
ConureApp::registerApps()
{
  registerApp(ConureApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ConureApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ConureApp::registerAll(f, af, s);
}
extern "C" void
ConureApp__registerApps()
{
  ConureApp::registerApps();
}
