// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Widgets/Container.hpp>

using namespace Arcanum;

void Container::Append(Widget* widget)
{
	_widgets.push_back(widget);
}

void Container::Draw()
{
	for (size_t i = 0; i < _widgets.size(); i++)
	{
		_widgets[i]->Draw();
	}
}
