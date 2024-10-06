function plotscope

% Да се начертае нолетоо от прави на у-нието y*y'=x в
% интервале К = [-5,5]^2
% В същия прозорец да се начертае графиката на решението на задачата на
% Коши с начално условие y(x0) = y0, където чрез кник в К.

% y' = f(x, y), (x, y) принадлежи на D подм-во на R, f: D -> R непрек.

% Поле от прави се нар. м-вото:
% P = {{(x, y) от R^2 | y - y0 = f(x0, y0)(x -x0)} | (x0, y0) от D}


x = -5 : 0.2 : 5;
y = -5 : 0.2 : 5;

function z = f(x, y)
z = x^y;
end

hold on
axis([-5, 5 -5, 5])

delta = 0.08;
for k = 1 : length(x)
    for j = 1 :length(y)
        eps = delta/sqrt(1+(f(x(k), y(j)))^2);
        plot([x(k) - eps, x(k) + eps], [y(j) - eps*f(x(k), y(j)), y(j) + eps*f(x(k), y(j))], 'k')
        plot(x(k), y(j), 'k.')
    end
end

end

