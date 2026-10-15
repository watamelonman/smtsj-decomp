SPECS=[('src/UniteEvent.c',[('UniteEvent_SetState','''void UniteEvent_SetState(UniteEvent *ev, s32 state)
{
    ev->state = state;
    FIELD(s32, ev, 604) = 0;
}''')],'')]
