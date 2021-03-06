/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2014      Jacky Tsang (zengrong.net)

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef CCSHARPEN_FILTER
#define CCSHARPEN_FILTER

#include "CCFilter.h"

NS_CC_EXT_BEGIN

//================== SharpenFilter

class SharpenFilter : public Filter
{

public:
	static SharpenFilter* create();
	static SharpenFilter* create(float sharpness, float widthFactor, float heightFactor);
	static SharpenFilter* create(float sharpness, int amount);

	SharpenFilter();

	void setParameter(float sharpness, float widthFactor, float heightFactor);
	void setParameter(float sharpness, int amount);
	virtual void initSprite(FilteredSprite* sprite);
protected:
	virtual GLProgram* loadShader();
	virtual void setAttributes(GLProgram* glp);
	virtual void setUniforms(GLProgram* glp);
	float _sharpness;
	float _widthFactor;
	float _heightFactor;
	int _amount;

};

NS_CC_EXT_END

#endif //CCSHARPEN_FILTER