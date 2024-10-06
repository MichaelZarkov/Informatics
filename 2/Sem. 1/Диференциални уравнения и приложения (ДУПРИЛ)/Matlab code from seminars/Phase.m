function Phase

x = -5:0.5:5;
y = -3:0.5:3;
Tm = 10;
axis([-6 6 -4 4]);
hold on
plot(0, 0, 'r*', -pi, 0 ,'r*', pi, 0, 'r*')
[X, Y] = meshgrid(x, y)
p = Y;
q = sin(X+Y)
D = sqrt(p.^2 + q.^2)
quiver(X, Y, p./D, q./D, 0.5, 'k')
[x0, y0] = ginput(1);
[T, Y] = ode45(@f, [0, Tm], [x0, y0])
x = Y(:, 1);
y = Y(:, 2)

for k = 1:length(T)
    xx(k) = x(k);
    yy(k) = y(k);
    plot(xx, yy, 'r')
    getframe;
end

function z = f(t, y)
z = [y(2); sin(y(1) + y(2))];
end

end