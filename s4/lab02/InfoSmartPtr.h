#pragma once
#include "InfoClass.h"
#include "InfoSuperClass.h"

class InfoSmartPtr {
public:
	InfoSmartPtr(InfoClass* ptr): m_ptr(ptr), m_qcounter(ptr->getCounter()) {
		(*m_qcounter)++;
	}
	~InfoSmartPtr() {
		(*m_qcounter)--;

		if (*m_qcounter == 0)
			delete m_ptr;
	}
	InfoSmartPtr(const InfoSmartPtr& o) {
		m_qcounter = o.m_qcounter;
		m_ptr = o.m_ptr;
		(*m_qcounter)++;
	}

	void operator=(const InfoSmartPtr& o) {
		this->~InfoSmartPtr();
		m_ptr = o.m_ptr;
		m_qcounter = o.m_qcounter;
		(*m_qcounter)++;
	}

	const InfoClass& operator*() const {return *m_ptr;}
	InfoClass& operator*() {return *m_ptr;}
	const InfoClass* operator->() const {return m_ptr;}
	InfoClass* operator->() {return m_ptr;}
private:
	InfoClass* m_ptr;
	int* m_qcounter;
};
