package org.asgalex.nativecontrols.datepicker;

import android.os.Bundle;
import android.app.Dialog;
import android.app.DialogFragment;
import android.app.DatePickerDialog;
import android.widget.DatePicker;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import java.util.Calendar;
import android.util.Log;

public class DatePickerFragment extends DialogFragment implements DatePickerDialog.OnDateSetListener {

    public int year;
    public int month;
    public int day;

    public static int dialogOpened = 0;

    public static void showMe(FragmentManager fragmentManager, int year, int month, int day)
    {
        if(DatePickerFragment.dialogOpened == 0)
        {
            DatePickerFragment newFragment = new DatePickerFragment();
            newFragment.year = year;
            newFragment.month = month;
            newFragment.day = day;

            DatePickerFragment.dialogOpened = 1;
            newFragment.show(fragmentManager, "datePicker");
        }
    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {

        final Calendar c = Calendar.getInstance();

        year = (year == -1) ? c.get(Calendar.YEAR) : year;
        month = (month == -1) ? c.get(Calendar.MONTH) : month;
        day = (day == -1) ? c.get(Calendar.DAY_OF_MONTH): day;

        return new DatePickerDialog(getActivity(), this, year, month, day);
    }

    public void onDateSet(DatePicker view, int year, int month, int day) {
        DatePickerFragment.dialogOpened = 0;
        sendDateToQt(year, month, day);
    }

    private static native void sendDateToQt(int year, int month, int day);
}
