#include "textbuffer.h"

#include <cstring>

TextBuffer::TextBuffer() : m_BufferBegin{nullptr}, m_BufferEnd{nullptr} {
	m_BufferBegin = new TextNode{};
	m_BufferEnd = m_BufferBegin;
	m_CursorNode = m_BufferBegin;
}
TextBuffer::TextBuffer(const char* initial_text){
	m_BufferBegin = new TextNode{};
	m_BufferEnd = m_BufferBegin;
	m_CursorNode = m_BufferBegin;

	insert(initial_text);
}
TextBuffer::~TextBuffer(){
	TextNode *where = m_BufferBegin;
	while(where->next != nullptr){
		where = where->next;
		delete where->previous;
	}
	delete where;
}

void TextBuffer::insert(const char* text){
	
}
 
