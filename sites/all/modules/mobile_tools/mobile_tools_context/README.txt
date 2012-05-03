Mobile Tools Context
====================

The term "context" is a wonderfully generic term. Because of this, the meaning of the term "context" depends on, well the context. This module integrates with the Context module as well as the concept of "contexts" in the CTools suite of modules (Chaos Tools, Panels, Views). Depending on which type of context you require, you'll need to follow some and/or all of the following steps.

Installation
------------

The module implements APIs from both the Context module and CTools plugins. Though this module doesn't require any of them to function, it does little of anything without at least one of those two modules enabled.

Your choice, but you should install at least one of Context or CTools and then enable this module

Usage
-----

Context Module
--------------

This module defines certain conditions and reactions to be used with the Context module. Use them as you would any other condition/reaction.

Ex:

1. Enable Context and Context UI (Context UI can be disabled after the configuration is complete)
2. Go to /admin/structure/context
3. Click "Add context"
4. Under the "conditions" and/or "reactions" sections, choose the mobile contexts you require (ex: condition - Mobile device)
5. Save your context

CTools
------

The CTools integration has a few more varied uses since it can be used with modules based on the CTools APIs. Most notably Views and Panels.

Panels Usage
------------

1. Create a panel page with two variants (name one mobile)
2. Under selection rules, choose 'Mobile browser'
3. Configure the settings on the next page

TODO
Views example