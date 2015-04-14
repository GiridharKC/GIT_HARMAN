void ApplNmCanNormal( CanChannelHandle channel )
{
   TRACE_VALUE(CAN_NM_CB_MSG, MOD_CAN, "CAN %d: ApplNmCanNormal", channel);

   if (channel == CAN_0)
   {
      // I-CAN: NM-Basic, TJA1042
      ApplNmBasicSwitchTransceiverOn();
   }
   else if (channel == CAN_1)
   {
      // MM-CAN: NM-OSEK, TJA1055
      CAN2_STBQ_DEACTIVATE;
      CAN2_EN_ACTIVATE;

      setTransceiverStatus(CAN_1, CAN_ON);  // status layer setzen
   }
   else if (channel == CAN_2)
   {
      // P2P-CAN: NM-OSEK, TJA1042
      CAN0_STBQ_ACTIVATE;

      setTransceiverStatus(CAN_2, CAN_ON);  // status layer setzen
   }
}
