% Specify the file path
file_path = 'Volt-EncVel.csv';

% Using readmatrix (introduced in MATLAB R2020a)
data_numeric_r2020a = readmatrix(file_path);
u=data_numeric_r2020a(:,1);
y=data_numeric_r2020a(:,3); %%Load deg/s
%%
%type ident to open system Identification tool

%% tf5
s=tf('s');
[Sys_num, Sys_den ]= tfdata(tf5);
Sys_s= tf(Sys_num, Sys_den);
set_param('Lab7/Sys_S', 'Numerator', "["+num2str(cell2mat(Sys_num))+"]", ...
    'Denominator', "["+num2str(cell2mat(Sys_den))+"]");
%% Tunung PID
%%%%%%%Third order 
%%%%%%%%%%% Response time = 0.3412 %%%%%%%%%%%%
%%%%%%%%%%% Transient Behaviour = 0.9 %%%%%%%%%%%%

%% Discretizing System
ST = 0.02; %Sampling time 
Sys_z=c2d(Sys_s*(1/s),ST,'tustin'); %%1/s to get position
[num_sys_z , den_sys_z ] = tfdata( Sys_z );
set_param('Lab7/Sys_Z', 'Numerator', "["+num2str(cell2mat(num_sys_z))+"]", ...
    'Denominator', "["+num2str(cell2mat(den_sys_z))+"]");
%% Discretizing PID
PID_Z_tustin = c2d(PID_S,ST,'tustin');
[ num_pid_z , den_pid_z ] = tfdata( PID_Z_tustin );
set_param('Lab7/Discrete_PID', 'Numerator', "["+num2str(cell2mat(num_pid_z))+"]", ...
    'Denominator', "["+num2str(cell2mat(den_pid_z))+"]");
tf(PID_Z_tustin);
