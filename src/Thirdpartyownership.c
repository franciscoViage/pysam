#include <Python.h>

#include <SAM_Thirdpartyownership.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * Depreciation Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thirdpartyownership   data_ptr;
} DepreciationObject;

static PyTypeObject Depreciation_Type;

static PyObject *
Depreciation_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = Depreciation_Type.tp_alloc(&Depreciation_Type,0);

	DepreciationObject* Depreciation_obj = (DepreciationObject*)new_obj;

	Depreciation_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Depreciation methods */

static PyObject *
Depreciation_assign(DepreciationObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "Depreciation")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Depreciation_export(DepreciationObject *self, PyObject *args)
{
	PyTypeObject* tp = &Depreciation_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Depreciation_methods[] = {
		{"assign",            (PyCFunction)Depreciation_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Depreciation_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Depreciation_get_depr_fed_custom(DepreciationObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Depreciation_depr_fed_custom_aget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_custom(DepreciationObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thirdpartyownership_Depreciation_depr_fed_custom_aset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_fed_sl_years(DepreciationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Depreciation_depr_fed_sl_years_fget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_sl_years(DepreciationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_Depreciation_depr_fed_sl_years_fset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_fed_type(DepreciationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Depreciation_depr_fed_type_fget, self->data_ptr);
}

static int
Depreciation_set_depr_fed_type(DepreciationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_Depreciation_depr_fed_type_fset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_custom(DepreciationObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Depreciation_depr_sta_custom_aget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_custom(DepreciationObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thirdpartyownership_Depreciation_depr_sta_custom_aset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_sl_years(DepreciationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Depreciation_depr_sta_sl_years_fget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_sl_years(DepreciationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_Depreciation_depr_sta_sl_years_fset, self->data_ptr);
}

static PyObject *
Depreciation_get_depr_sta_type(DepreciationObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Depreciation_depr_sta_type_fget, self->data_ptr);
}

static int
Depreciation_set_depr_sta_type(DepreciationObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_Depreciation_depr_sta_type_fset, self->data_ptr);
}

static PyGetSetDef Depreciation_getset[] = {
{"depr_fed_custom", (getter)Depreciation_get_depr_fed_custom,(setter)Depreciation_set_depr_fed_custom,
	"Federal custom depreciation [%/year], array.\n Required if: depr_fed_type=3.",
 	NULL},
{"depr_fed_sl_years", (getter)Depreciation_get_depr_fed_sl_years,(setter)Depreciation_set_depr_fed_sl_years,
	"Federal depreciation straight-line Years [years], number.\n Constraints: INTEGER,POSITIVE; Required if: depr_fed_type=2.",
 	NULL},
{"depr_fed_type", (getter)Depreciation_get_depr_fed_type,(setter)Depreciation_set_depr_fed_type,
	"Federal depreciation type [], number.\n 0=none,1=macrs_half_year,2=sl,3=custom; Constraints: INTEGER,MIN=0,MAX=3; Required if: ?=0.",
 	NULL},
{"depr_sta_custom", (getter)Depreciation_get_depr_sta_custom,(setter)Depreciation_set_depr_sta_custom,
	"State custom depreciation [%/year], array.\n Required if: depr_sta_type=3.",
 	NULL},
{"depr_sta_sl_years", (getter)Depreciation_get_depr_sta_sl_years,(setter)Depreciation_set_depr_sta_sl_years,
	"State depreciation straight-line years [years], number.\n Constraints: INTEGER,POSITIVE; Required if: depr_sta_type=2.",
 	NULL},
{"depr_sta_type", (getter)Depreciation_get_depr_sta_type,(setter)Depreciation_set_depr_sta_type,
	"State depreciation type [], number.\n 0=none,1=macrs_half_year,2=sl,3=custom; Constraints: INTEGER,MIN=0,MAX=3; Required if: ?=0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Depreciation_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.Depreciation",             /*tp_name*/
		sizeof(DepreciationObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Depreciation_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Depreciation_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Financials Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thirdpartyownership   data_ptr;
} FinancialsObject;

static PyTypeObject Financials_Type;

static PyObject *
Financials_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = Financials_Type.tp_alloc(&Financials_Type,0);

	FinancialsObject* Financials_obj = (FinancialsObject*)new_obj;

	Financials_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Financials methods */

static PyObject *
Financials_assign(FinancialsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "Financials")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Financials_export(FinancialsObject *self, PyObject *args)
{
	PyTypeObject* tp = &Financials_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Financials_methods[] = {
		{"assign",            (PyCFunction)Financials_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Financials_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Financials_get_analysis_period(FinancialsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Financials_analysis_period_fget, self->data_ptr);
}

static int
Financials_set_analysis_period(FinancialsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_Financials_analysis_period_fset, self->data_ptr);
}

static PyObject *
Financials_get_inflation_rate(FinancialsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Financials_inflation_rate_fget, self->data_ptr);
}

static int
Financials_set_inflation_rate(FinancialsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_Financials_inflation_rate_fset, self->data_ptr);
}

static PyObject *
Financials_get_real_discount_rate(FinancialsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Financials_real_discount_rate_fget, self->data_ptr);
}

static int
Financials_set_real_discount_rate(FinancialsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_Financials_real_discount_rate_fset, self->data_ptr);
}

static PyGetSetDef Financials_getset[] = {
{"analysis_period", (getter)Financials_get_analysis_period,(setter)Financials_set_analysis_period,
	"Analyis period [years], number.\n Constraints: INTEGER,MIN=0,MAX=50; Required if: ?=30.",
 	NULL},
{"inflation_rate", (getter)Financials_get_inflation_rate,(setter)Financials_set_inflation_rate,
	"Inflation rate [%], number.\n Constraints: MIN=-99; Required if: *.",
 	NULL},
{"real_discount_rate", (getter)Financials_get_real_discount_rate,(setter)Financials_set_real_discount_rate,
	"Real discount rate [%], number.\n Constraints: MIN=-99; Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Financials_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.Financials",             /*tp_name*/
		sizeof(FinancialsObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Financials_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Financials_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * FinancialThirdPartyOwnership Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thirdpartyownership   data_ptr;
} FinancialThirdPartyOwnershipObject;

static PyTypeObject FinancialThirdPartyOwnership_Type;

static PyObject *
FinancialThirdPartyOwnership_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = FinancialThirdPartyOwnership_Type.tp_alloc(&FinancialThirdPartyOwnership_Type,0);

	FinancialThirdPartyOwnershipObject* FinancialThirdPartyOwnership_obj = (FinancialThirdPartyOwnershipObject*)new_obj;

	FinancialThirdPartyOwnership_obj->data_ptr = data_ptr;

	return new_obj;
}

/* FinancialThirdPartyOwnership methods */

static PyObject *
FinancialThirdPartyOwnership_assign(FinancialThirdPartyOwnershipObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "FinancialThirdPartyOwnership")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialThirdPartyOwnership_export(FinancialThirdPartyOwnershipObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialThirdPartyOwnership_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialThirdPartyOwnership_methods[] = {
		{"assign",            (PyCFunction)FinancialThirdPartyOwnership_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)FinancialThirdPartyOwnership_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialThirdPartyOwnership_get_lease_or_ppa(FinancialThirdPartyOwnershipObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_FinancialThirdPartyOwnership_lease_or_ppa_fget, self->data_ptr);
}

static int
FinancialThirdPartyOwnership_set_lease_or_ppa(FinancialThirdPartyOwnershipObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_FinancialThirdPartyOwnership_lease_or_ppa_fset, self->data_ptr);
}

static PyGetSetDef FinancialThirdPartyOwnership_getset[] = {
{"lease_or_ppa", (getter)FinancialThirdPartyOwnership_get_lease_or_ppa,(setter)FinancialThirdPartyOwnership_set_lease_or_ppa,
	"Lease or PPA agreement [0/1], number.\n 0=lease,1=ppa; Constraints: INTEGER,MIN=0,MAX=1; Required if: ?=0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialThirdPartyOwnership_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.FinancialThirdPartyOwnership",             /*tp_name*/
		sizeof(FinancialThirdPartyOwnershipObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		FinancialThirdPartyOwnership_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialThirdPartyOwnership_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Common Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thirdpartyownership   data_ptr;
} CommonObject;

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	CommonObject* Common_obj = (CommonObject*)new_obj;

	Common_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(CommonObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(CommonObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_annual_energy_value(CommonObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Common_annual_energy_value_aget, self->data_ptr);
}

static int
Common_set_annual_energy_value(CommonObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thirdpartyownership_Common_annual_energy_value_aset, self->data_ptr);
}

static PyObject *
Common_get_gen(CommonObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Common_gen_aget, self->data_ptr);
}

static int
Common_set_gen(CommonObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thirdpartyownership_Common_gen_aset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"annual_energy_value", (getter)Common_get_annual_energy_value,(setter)Common_set_annual_energy_value,
	"Energy value [$], array.\n Required if: *.",
 	NULL},
{"gen", (getter)Common_get_gen,(setter)Common_set_gen,
	"Power generated by renewable resource [kW], array.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.Common",             /*tp_name*/
		sizeof(CommonObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * AnnualOutput Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thirdpartyownership   data_ptr;
} AnnualOutputObject;

static PyTypeObject AnnualOutput_Type;

static PyObject *
AnnualOutput_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = AnnualOutput_Type.tp_alloc(&AnnualOutput_Type,0);

	AnnualOutputObject* AnnualOutput_obj = (AnnualOutputObject*)new_obj;

	AnnualOutput_obj->data_ptr = data_ptr;

	return new_obj;
}

/* AnnualOutput methods */

static PyObject *
AnnualOutput_assign(AnnualOutputObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "AnnualOutput")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AnnualOutput_export(AnnualOutputObject *self, PyObject *args)
{
	PyTypeObject* tp = &AnnualOutput_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef AnnualOutput_methods[] = {
		{"assign",            (PyCFunction)AnnualOutput_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)AnnualOutput_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
AnnualOutput_get_degradation(AnnualOutputObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_AnnualOutput_degradation_aget, self->data_ptr);
}

static int
AnnualOutput_set_degradation(AnnualOutputObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thirdpartyownership_AnnualOutput_degradation_aset, self->data_ptr);
}

static PyObject *
AnnualOutput_get_system_use_lifetime_output(AnnualOutputObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_AnnualOutput_system_use_lifetime_output_fget, self->data_ptr);
}

static int
AnnualOutput_set_system_use_lifetime_output(AnnualOutputObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_AnnualOutput_system_use_lifetime_output_fset, self->data_ptr);
}

static PyGetSetDef AnnualOutput_getset[] = {
{"degradation", (getter)AnnualOutput_get_degradation,(setter)AnnualOutput_set_degradation,
	"Annual degradation [%], array.\n Required if: *.",
 	NULL},
{"system_use_lifetime_output", (getter)AnnualOutput_get_system_use_lifetime_output,(setter)AnnualOutput_set_system_use_lifetime_output,
	"Lifetime hourly system outputs [0/1], number.\n 0=hourly first year,1=hourly lifetime; Constraints: INTEGER,MIN=0; Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject AnnualOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.AnnualOutput",             /*tp_name*/
		sizeof(AnnualOutputObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		AnnualOutput_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		AnnualOutput_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * CashFlow Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thirdpartyownership   data_ptr;
} CashFlowObject;

static PyTypeObject CashFlow_Type;

static PyObject *
CashFlow_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = CashFlow_Type.tp_alloc(&CashFlow_Type,0);

	CashFlowObject* CashFlow_obj = (CashFlowObject*)new_obj;

	CashFlow_obj->data_ptr = data_ptr;

	return new_obj;
}

/* CashFlow methods */

static PyObject *
CashFlow_assign(CashFlowObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "CashFlow")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CashFlow_export(CashFlowObject *self, PyObject *args)
{
	PyTypeObject* tp = &CashFlow_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef CashFlow_methods[] = {
		{"assign",            (PyCFunction)CashFlow_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)CashFlow_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CashFlow_get_lease_escalation(CashFlowObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_CashFlow_lease_escalation_fget, self->data_ptr);
}

static int
CashFlow_set_lease_escalation(CashFlowObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_CashFlow_lease_escalation_fset, self->data_ptr);
}

static PyObject *
CashFlow_get_lease_price(CashFlowObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_CashFlow_lease_price_fget, self->data_ptr);
}

static int
CashFlow_set_lease_price(CashFlowObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_CashFlow_lease_price_fset, self->data_ptr);
}

static PyObject *
CashFlow_get_ppa_escalation(CashFlowObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_CashFlow_ppa_escalation_fget, self->data_ptr);
}

static int
CashFlow_set_ppa_escalation(CashFlowObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_CashFlow_ppa_escalation_fset, self->data_ptr);
}

static PyObject *
CashFlow_get_ppa_price(CashFlowObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_CashFlow_ppa_price_fget, self->data_ptr);
}

static int
CashFlow_set_ppa_price(CashFlowObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thirdpartyownership_CashFlow_ppa_price_fset, self->data_ptr);
}

static PyGetSetDef CashFlow_getset[] = {
{"lease_escalation", (getter)CashFlow_get_lease_escalation,(setter)CashFlow_set_lease_escalation,
	"Monthly lease escalation [%/year], number.\n Required if: lease_or_ppa=0.",
 	NULL},
{"lease_price", (getter)CashFlow_get_lease_price,(setter)CashFlow_set_lease_price,
	"Monthly lease price [$/month], number.\n Required if: lease_or_ppa=0.",
 	NULL},
{"ppa_escalation", (getter)CashFlow_get_ppa_escalation,(setter)CashFlow_set_ppa_escalation,
	"Monthly lease escalation [%/year], number.\n Required if: lease_or_ppa=1.",
 	NULL},
{"ppa_price", (getter)CashFlow_get_ppa_price,(setter)CashFlow_set_ppa_price,
	"Monthly lease price [$/month], number.\n Required if: lease_or_ppa=1.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject CashFlow_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.CashFlow",             /*tp_name*/
		sizeof(CashFlowObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		CashFlow_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		CashFlow_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * ElectricityCost Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thirdpartyownership   data_ptr;
} ElectricityCostObject;

static PyTypeObject ElectricityCost_Type;

static PyObject *
ElectricityCost_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = ElectricityCost_Type.tp_alloc(&ElectricityCost_Type,0);

	ElectricityCostObject* ElectricityCost_obj = (ElectricityCostObject*)new_obj;

	ElectricityCost_obj->data_ptr = data_ptr;

	return new_obj;
}

/* ElectricityCost methods */

static PyObject *
ElectricityCost_assign(ElectricityCostObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "ElectricityCost")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricityCost_export(ElectricityCostObject *self, PyObject *args)
{
	PyTypeObject* tp = &ElectricityCost_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ElectricityCost_methods[] = {
		{"assign",            (PyCFunction)ElectricityCost_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)ElectricityCost_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ElectricityCost_get_elec_cost_with_system(ElectricityCostObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_ElectricityCost_elec_cost_with_system_aget, self->data_ptr);
}

static int
ElectricityCost_set_elec_cost_with_system(ElectricityCostObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thirdpartyownership_ElectricityCost_elec_cost_with_system_aset, self->data_ptr);
}

static PyObject *
ElectricityCost_get_elec_cost_without_system(ElectricityCostObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_ElectricityCost_elec_cost_without_system_aget, self->data_ptr);
}

static int
ElectricityCost_set_elec_cost_without_system(ElectricityCostObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thirdpartyownership_ElectricityCost_elec_cost_without_system_aset, self->data_ptr);
}

static PyGetSetDef ElectricityCost_getset[] = {
{"elec_cost_with_system", (getter)ElectricityCost_get_elec_cost_with_system,(setter)ElectricityCost_set_elec_cost_with_system,
	"Energy value [$], array.\n Required if: *.",
 	NULL},
{"elec_cost_without_system", (getter)ElectricityCost_get_elec_cost_without_system,(setter)ElectricityCost_set_elec_cost_without_system,
	"Energy value [$], array.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricityCost_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.ElectricityCost",             /*tp_name*/
		sizeof(ElectricityCostObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		ElectricityCost_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ElectricityCost_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Outputs Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thirdpartyownership   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Thirdpartyownership data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	OutputsObject* Outputs_obj = (OutputsObject*)new_obj;

	Outputs_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(OutputsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thirdpartyownership", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_export(OutputsObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_cf_after_tax_cash_flow(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_after_tax_cash_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_after_tax_net_equity_cost_flow(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_after_tax_net_equity_cost_flow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_agreement_cost(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_agreement_cost_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_cumulative_payback_with_expenses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_cumulative_payback_with_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_energy_net(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_energy_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_length(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Outputs_cf_length_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_nte(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_nte_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cf_payback_with_expenses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thirdpartyownership_Outputs_cf_payback_with_expenses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_lnte_nom(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Outputs_lnte_nom_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lnte_real(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Outputs_lnte_real_fget, self->data_ptr);
}

static PyObject *
Outputs_get_npv(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Outputs_npv_fget, self->data_ptr);
}

static PyObject *
Outputs_get_year1_nte(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thirdpartyownership_Outputs_year1_nte_fget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"cf_after_tax_cash_flow", (getter)Outputs_get_cf_after_tax_cash_flow,(setter)0,
	"After-tax cash flow [$], array.",
 	NULL},
{"cf_after_tax_net_equity_cost_flow", (getter)Outputs_get_cf_after_tax_net_equity_cost_flow,(setter)0,
	"After-tax annual costs [$], array.",
 	NULL},
{"cf_agreement_cost", (getter)Outputs_get_cf_agreement_cost,(setter)0,
	"Agreement cost [$], array.",
 	NULL},
{"cf_cumulative_payback_with_expenses", (getter)Outputs_get_cf_cumulative_payback_with_expenses,(setter)0,
	"Cumulative simple payback with expenses [$], array.",
 	NULL},
{"cf_energy_net", (getter)Outputs_get_cf_energy_net,(setter)0,
	"Energy [kWh], array.",
 	NULL},
{"cf_length", (getter)Outputs_get_cf_length,(setter)0,
	"Agreement period [], number.",
 	NULL},
{"cf_nte", (getter)Outputs_get_cf_nte,(setter)0,
	"Host indifference point by year [cents/kWh], array.",
 	NULL},
{"cf_payback_with_expenses", (getter)Outputs_get_cf_payback_with_expenses,(setter)0,
	"Simple payback with expenses [$], array.",
 	NULL},
{"lnte_nom", (getter)Outputs_get_lnte_nom,(setter)0,
	"Host indifference point real levelized value [cents/kWh], number.",
 	NULL},
{"lnte_real", (getter)Outputs_get_lnte_real,(setter)0,
	"Host indifference point nominal levelized value [cents/kWh], number.",
 	NULL},
{"npv", (getter)Outputs_get_npv,(setter)0,
	"Net present value [$], number.",
 	NULL},
{"year1_nte", (getter)Outputs_get_year1_nte,(setter)0,
	"Host indifference point in Year 1 [cents/kWh], number.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership.Outputs",             /*tp_name*/
		sizeof(OutputsObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/*
 * Thirdpartyownership
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Thirdpartyownership   data_ptr;
} ThirdpartyownershipObject;

static PyTypeObject Thirdpartyownership_Type;

#define ThirdpartyownershipObject_Check(v)      (Py_TYPE(v) == &Thirdpartyownership_Type)

static ThirdpartyownershipObject *
newThirdpartyownershipObject(void* data_ptr)
{
	ThirdpartyownershipObject *self;
	self = PyObject_New(ThirdpartyownershipObject, &Thirdpartyownership_Type);

	PySAM_TECH_ATTR("Thirdpartyownership", SAM_Thirdpartyownership_construct)

PyObject* Depreciation_obj = Depreciation_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Depreciation", Depreciation_obj);
	Py_DECREF(Depreciation_obj);

PyObject* Financials_obj = Financials_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Financials", Financials_obj);
	Py_DECREF(Financials_obj);

PyObject* FinancialThirdPartyOwnership_obj = FinancialThirdPartyOwnership_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialThirdPartyOwnership", FinancialThirdPartyOwnership_obj);
	Py_DECREF(FinancialThirdPartyOwnership_obj);

PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

PyObject* AnnualOutput_obj = AnnualOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "AnnualOutput", AnnualOutput_obj);
	Py_DECREF(AnnualOutput_obj);

PyObject* CashFlow_obj = CashFlow_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "CashFlow", CashFlow_obj);
	Py_DECREF(CashFlow_obj);

PyObject* ElectricityCost_obj = ElectricityCost_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityCost", ElectricityCost_obj);
	Py_DECREF(ElectricityCost_obj);

PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");

	PyObject* data_cap = PyCapsule_New(self->data_ptr, NULL, NULL);
	PyObject* Adjust_obj = PyObject_CallMethod(AdjustmentFactorsModule, "new", "(O)", data_cap);
	Py_XDECREF(data_cap);
	Py_XDECREF(AdjustmentFactorsModule);

	if (!Adjust_obj){
		PyErr_SetString(PySAM_ErrorObject, "Couldn't create AdjustmentFactorsObject\n");
		return NULL;
	}

	PyDict_SetItemString(attr_dict, "AdjustmentFactors", Adjust_obj);
	Py_DECREF(Adjust_obj);

	return self;
}

/* Thirdpartyownership methods */

static void
Thirdpartyownership_dealloc(ThirdpartyownershipObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Thirdpartyownership_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Thirdpartyownership_execute(ThirdpartyownershipObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Thirdpartyownership_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Thirdpartyownership_assign(ThirdpartyownershipObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Thirdpartyownership"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Thirdpartyownership_export(ThirdpartyownershipObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef Thirdpartyownership_methods[] = {
		{"execute",            (PyCFunction)Thirdpartyownership_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Thirdpartyownership_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Thirdpartyownership_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Thirdpartyownership_getattro(ThirdpartyownershipObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Thirdpartyownership_setattr(ThirdpartyownershipObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Thirdpartyownership_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thirdpartyownership",            /*tp_name*/
		sizeof(ThirdpartyownershipObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Thirdpartyownership_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Thirdpartyownership_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Thirdpartyownership_getattro, /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		"see html for help",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Thirdpartyownership_methods,      /*tp_methods*/
		0,                          /*tp_members*/
		0,       /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,                          /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/* --------------------------------------------------------------------- */


/* Function of no arguments returning new Thirdpartyownership object */

static PyObject *
Thirdpartyownership_new(PyObject *self, PyObject *args)
{
	ThirdpartyownershipObject *rv;
	rv = newThirdpartyownershipObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Thirdpartyownership_wrap(PyObject *self, PyObject *args)
{
	ThirdpartyownershipObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newThirdpartyownershipObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Thirdpartyownership_default(PyObject *self, PyObject *args)
{
	ThirdpartyownershipObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newThirdpartyownershipObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Thirdpartyownership", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef ThirdpartyownershipModule_methods[] = {
		{"new",             Thirdpartyownership_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Thirdpartyownership object")},
		{"default",             Thirdpartyownership_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Thirdpartyownership object with financial model-specific default attributes\n"
				"Options: All Equity Partnership Flip, None, LCOE Calculator, Independent Power Producer, Commercial, Third Party, Residential, Leveraged Partnership Flip, Single Owner, Sale Leaseback, Commercial PPA, Host Developer, ")},
		{"wrap",             Thirdpartyownership_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Thirdpartyownership object around existing PySSC data")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Refer to http://www.github.com/nrel/PySAM for source code.");


static int
ThirdpartyownershipModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	Thirdpartyownership_Type.tp_dict = PyDict_New();
	if (!Thirdpartyownership_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Thirdpartyownership_Type
	PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");
	if (!AdjustmentFactorsModule){
		PyErr_SetImportError(PyUnicode_FromString("Could not import AdjustmentFactors module."), NULL, NULL);
	}

	PyTypeObject* AdjustmentFactors_Type = (PyTypeObject*)PyObject_GetAttrString(AdjustmentFactorsModule, "AdjustmentFactors");
	if (!AdjustmentFactors_Type){
		PyErr_SetImportError(PyUnicode_FromString("Could not import AdjustmentFactors type."), NULL, NULL);
	}
	Py_XDECREF(AdjustmentFactorsModule);

	if (PyType_Ready(AdjustmentFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Depreciation type object to Thirdpartyownership_Type
	if (PyType_Ready(&Depreciation_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"Depreciation",
				(PyObject*)&Depreciation_Type);
	Py_DECREF(&Depreciation_Type);

	/// Add the Financials type object to Thirdpartyownership_Type
	if (PyType_Ready(&Financials_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"Financials",
				(PyObject*)&Financials_Type);
	Py_DECREF(&Financials_Type);

	/// Add the FinancialThirdPartyOwnership type object to Thirdpartyownership_Type
	if (PyType_Ready(&FinancialThirdPartyOwnership_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"FinancialThirdPartyOwnership",
				(PyObject*)&FinancialThirdPartyOwnership_Type);
	Py_DECREF(&FinancialThirdPartyOwnership_Type);

	/// Add the Common type object to Thirdpartyownership_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the AnnualOutput type object to Thirdpartyownership_Type
	if (PyType_Ready(&AnnualOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"AnnualOutput",
				(PyObject*)&AnnualOutput_Type);
	Py_DECREF(&AnnualOutput_Type);

	/// Add the CashFlow type object to Thirdpartyownership_Type
	if (PyType_Ready(&CashFlow_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"CashFlow",
				(PyObject*)&CashFlow_Type);
	Py_DECREF(&CashFlow_Type);

	/// Add the ElectricityCost type object to Thirdpartyownership_Type
	if (PyType_Ready(&ElectricityCost_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"ElectricityCost",
				(PyObject*)&ElectricityCost_Type);
	Py_DECREF(&ElectricityCost_Type);

	/// Add the Outputs type object to Thirdpartyownership_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thirdpartyownership_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Thirdpartyownership type object to the module
	if (PyType_Ready(&Thirdpartyownership_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Thirdpartyownership",
				(PyObject*)&Thirdpartyownership_Type);

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot ThirdpartyownershipModule_slots[] = {
		{Py_mod_exec, ThirdpartyownershipModule_exec},
		{0, NULL},
};

static struct PyModuleDef ThirdpartyownershipModule = {
		PyModuleDef_HEAD_INIT,
		"Thirdpartyownership",
		module_doc,
		0,
		ThirdpartyownershipModule_methods,
		ThirdpartyownershipModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Thirdpartyownership(void)
{
	return PyModuleDef_Init(&ThirdpartyownershipModule);
}