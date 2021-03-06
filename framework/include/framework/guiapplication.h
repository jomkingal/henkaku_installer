/*
 * guiapplication.h - provide event and gui handling for application
 *
 * Copyright (C) 2016 David "Davee" Morgan
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef GUIAPPLICATION_H
#define GUIAPPLICATION_H

#include <memory>
#include <vector>

class View;
using ViewPtr = std::shared_ptr<View>;
using ViewPtrList = std::vector<ViewPtr>;

class Task;
using TaskPtr = std::shared_ptr<Task>;

class Screen;
class Input;
class Event;

class GuiApplication
{
public:
	GuiApplication(int argc, char **argv);
	~GuiApplication(void);

	static int exec(void);

	static ViewPtr focusedView(void);
	static ViewPtrList allViews(void);

	static void addView(ViewPtr view);

	static void sendEvent(Event *event);
	static void exit(void);

private:
	static GuiApplication *self;

private:
	Screen *platform_screen;
	Input *platform_input;
	ViewPtr focused_view;
	ViewPtrList view_list;
	TaskPtr update_task, draw_task;
	bool running;
};

#endif // GUIAPPLICATION_H
