#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];

double Output_REX[SIG_LENGTH/2];
double Output_IMX[SIG_LENGTH/2];
double Output_IDFT[SIG_LENGTH/2];

void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_lenght);
void sig_calc_idft(double *idft_out_arr, double *sig_src_rex_arr, double *sig_src_imx_arr, int idft_length);

int main()
{
    FILE *fptr, *fptr2, *fptr3, *fptr4;

    calc_sig_dft((double*) &InputSignal_f32_1kHz_15kHz[0], (double*) &Output_REX[0], (double*) &Output_IMX[0], (int) SIG_LENGTH);
    sig_calc_idft((double*) &Output_IDFT[0], (double*) &Output_REX[0], (double*) &Output_IMX[0], (int) SIG_LENGTH);


    fptr = fopen("input_signal.dat", "w");
    fptr2 = fopen("output_rex.dat","w");
    fptr3 = fopen("output_imx.dat","w");
    fptr4 = fopen("output_idft.dat","w");


    for(int i = 0; i<SIG_LENGTH;i++)
    {
        fprintf(fptr, "\n%f",InputSignal_f32_1kHz_15kHz[i]);
        fprintf(fptr4, "\n%f",Output_IDFT[i]);

    }

    for(int i = 0; i<SIG_LENGTH/2;i++)
    {
        fprintf(fptr2, "\n%f",Output_REX[i]);
        fprintf(fptr3, "\n%f",Output_IMX[i]);
    }

    fclose(fptr);
    fclose(fptr2);
    fclose(fptr3);

    return 0;
}

void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_lenght)
{
    int i,j,k;
    double PI = 3.14159265359;

    for(j=0; j<sig_lenght/2; j++)
    {
        sig_dest_rex_arr[j] =0;
        sig_dest_imx_arr[j] =0;
    }

    for(k =0; k<(sig_lenght/2);k++)
    {
        for(i=0; i<sig_lenght;i++)
        {
            sig_dest_rex_arr[k] = sig_dest_rex_arr[k] + sig_src_arr[i]*cos(2*PI*k*i/sig_lenght);
            sig_dest_imx_arr[k] = sig_dest_imx_arr[k] - sig_src_arr[i]*sin(2*PI*k*i/sig_lenght);
        }
    }
}

void sig_calc_idft(double *idft_out_arr, double *sig_src_rex_arr, double *sig_src_imx_arr, int idft_length)
{
    double PI = 3.14159265359;
    int i,k;
    for (k=0; k<idft_length/2; k++)
    {
        sig_src_rex_arr[k] = sig_src_rex_arr[k]/(idft_length/2);
        sig_src_imx_arr[k] = -sig_src_imx_arr[k]/(idft_length/2);
    }

    sig_src_rex_arr[0] = sig_src_rex_arr[0]/2;
    sig_src_imx_arr[0] = -sig_src_imx_arr[0]/2;

    for (i=0; i<idft_length; i++)
    {
        idft_out_arr[i]=0;
    }

    for (k=0; k<idft_length/2; k++)
    {
        for(i=0; i<idft_length ;i++)
        {
                idft_out_arr[i]= idft_out_arr[i] + sig_src_rex_arr[k]*cos(2*PI*k*idft_length);
                idft_out_arr[i]= idft_out_arr[i] + sig_src_imx_arr[k] *sin(2*PI*k*idft_length);
        }
    }
}
