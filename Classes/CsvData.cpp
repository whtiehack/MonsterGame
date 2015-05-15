#include "CsvData.h"
USING_NS_CC;
bool CsvData::init()
{
	return true;
}
void CsvData::addLineData(ValueVector lineData)
{
	m_allLinesVec.push_back(Value(lineData));
	m_iColNum=lineData.size();
}

ValueVector CsvData::getSingleLineData(int iLine)
{
	return m_allLinesVec.at(iLine).asValueVector();
}

Size CsvData::getRowColNum()
{
	Size size=Size();
	size.width=m_allLinesVec.size();
	if(size.width>0)
	{
		size.height=m_allLinesVec.at(0).asValueVector().size();	
	}
	return size;
}