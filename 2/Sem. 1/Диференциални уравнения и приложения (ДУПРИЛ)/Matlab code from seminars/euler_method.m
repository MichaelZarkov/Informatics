function euler_method
% Euler method for approximating the solution of a zadacha na Koshi.

x0 = 0; y0 = 1;
xmax = 2;
syms y(x)

% Draw the graph of the solution function.
%yy = dsolve(diff(y) == - y*tan(x) + (cos(x))^2, y(0) == 1);
yy = dsolve('Dy = -y*tan(x) + (cos(x))^2', 'y(0) = 1', 'x');
s = x0 : (xmax - x0) / 100 : xmax;
z = subs(yy, 'x', s);
plot(s, z, 'k')
hold on

% Euler method
h = [0.5, 0.2, 0.01];
x(1) = x0;
y(1) = y0;
for k = 1 : length(h)
    x = x0 : h(k) : xmax;
    for j = 1 : length(x) - 1
        y(j+1)=y(j)+h(k)*(-y(j)*tan(x(j))+(cos(x(j)))^2);
        
    end
    plot(x, y)
    hold on
end

end