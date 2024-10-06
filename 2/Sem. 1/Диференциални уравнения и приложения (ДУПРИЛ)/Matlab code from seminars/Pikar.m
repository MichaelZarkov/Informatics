function Pikar

% Скрипт, който чертае редицата от функции клонящи към решението на
% диф. у-ние

hold on
grid on

Xmin = -4;
Xmax = 4;

x0 = 0;
y0 = 1;

axis([Xmin Xmax -10 10])
syms y(x)

y = dsolve(diff(y) == y, y(x0) == y0);
x = Xmin : (Xmax - Xmin) / 100 : Xmax;

plot(x, eval(y), 'r')   % Plot of the final solution
x = x0 : (Xmin - x0) / 100 : Xmin;
xx = x0 : (Xmax - x0) / 100 : Xmax;

y_0 = y0 * ones(1, length(x));
yy_0 = y0 * ones(1, length(xx));

plot(x, y_0, 'b', xx, yy_0, 'b')  % The initial aproximation (const function)

z = y_0; zz = yy_0;
for k = 1 : 20
    y_k = y0 + cumtrapz(x, f(x, z));
    yy_k = y0 + cumtrapz(xx, f(xx, zz));
   
    z = y_k;
    zz = yy_k;
    
    plot(x, z, 'b', xx, zz, ' b') % Plot the k aproximations
end

 

 function z = f(x, y);
             z = y
    end

end