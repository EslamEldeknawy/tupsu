
void lr ()
{
  if (right.released())
    menu = menu + 1;
  if (left.released())
    menu = menu - 1;
  if (menu < 1)
  {
    menu = 0;
  }
}


void volts1 ()
{
  if (up.released())
    v_limit = v_limit + 1.00;
  if (down.released())
    v_limit = v_limit - 1.00;
  if (v_limit < 0)
  {
    v_limit = 9;
  }
}


void volts1_1 ()
{
  if (up.released())
    v_limit = v_limit + 0.100;
  if (down.released())
    v_limit = v_limit - 0.100;
  if (v_limit < 0)
  {
    v_limit = 9;
  }
}

void volts1_1_1 ()
{
  if (up.released())
    v_limit = v_limit + 0.010;
  if (down.released())
    v_limit = v_limit - 0.010;
  if (v_limit < 0)
  {
    v_limit = 9;
  }
}

void amp1 ()
{
  if (up.released())
    i_limit = i_limit + 1.00;
  if (down.released())
    i_limit = i_limit - 1.00;
  if (i_limit < 0)
  {
    i_limit = 4.5;
  }
  else if (i_limit > 4.5)
    i_limit = 0.01;
}

void amp1_1 ()
{
  if (up.released())
    i_limit = i_limit + 0.100;
  if (down.released())
    i_limit = i_limit - 0.100;
  if (i_limit < 0)
  {
    i_limit = 4.5;
  }
}

void amp1_1_1 ()
{
  if (up.released())
    i_limit = i_limit + 0.010;
  if (down.released())
    i_limit = i_limit - 0.010;
  if (i_limit < 0)
  {
    i_limit = 4.5;
  }
}
